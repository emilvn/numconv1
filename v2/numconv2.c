#include "../lib/string/not_string.h"
#include<stdio.h>

int base_x_to_int(int base, char *str)
{
    int val = 0;
    int length = not_strlen(str);
    int negative = 0;

    if(str[0] == 0x2D && base == 0xA){
            negative = 0x1;
    }

    for (int i = negative; i < length; i++) {
        if (base == 0x2) {
            val <<= 0x1; // each step we left shift by 1 bit(* 2) as we go from 1s to 2s to 4s etc.
            val |= str[i] & 0xF; // mask with 0xF to get the integer value of the char(0 or 1) and add it to val by OR
        } else if (base == 0x10) {
            val <<= 0x4; // each step we left shift by 4 bits(* 16) as we go from 1s to 16s to 256s etc.
            if(str[i] >= 0x30 && str[i] <= 0x39){ // if the char is a decimal number
                val |= str[i] & 0xF; // mask with 0xF to get the integer value of the char(0-9) and add it to val by OR
            } else {
                val |= (str[i] & 0xF) + 0x9; // if the char is a lette we mask as above and add 9 to get the decimal value of the letter(10-15)
            }
        } else {
            val *= base;
            if(base <= 0xA){
                val += str[i] - 0x30;
            }
        }
    }

    if(negative == 0x1 && base == 0xA){
        val = -val;
    }

    return val;
}

int dec_to_int(char *str)
{
    return base_x_to_int(0xA, str);
}

int bin_to_int(char* str)
{
    return base_x_to_int(0x2, str);
}

int hex_to_int(char* str)
{
    return base_x_to_int(0x10, str);
}

int oct_to_int(char* str)
{
    return base_x_to_int(0xA, str);
}

void int_to_base_x(int num, char *dest, int base)
{
    int pos = 0;
    int negative = 0;
    unsigned int rest = num;

    if (num < 0 && base == 0xA) {
        negative = 0x1;
        rest = -rest;
    }

     // calc amount of digits for binary
    int num_digits = 0;
    unsigned int tmp = rest;
    do {
        num_digits++;
        tmp /= base;
    } while (tmp > 0);

    // calc amount of leading 0's needed for binary
    int leading_zeros = 0;
    if (base == 0x2) {
        leading_zeros = (0x4 - (num_digits % 0x4)) % 0x4;
    }

    do {
        if (pos != 0 && (((base == 0x2 || base == 0x10) && pos % 0x5 == 0x4) || (base == 0x8 && pos % 0x4 == 0x3))) {
            dest[pos++] = 0x20;
        } else if (base == 0xA && pos % 0x4 == 0x3) {
            dest[pos++] = 0x2C;
        }

        int d;
        if (base == 0x2) {
            d = rest & 0x1; // mask with 1 to get the last bit
            rest >>= 0x1; // right shift the rest to remove the last digit
        } else if (base == 0x10) {
            d = rest & 0xF; // mask with 4 to get the last 4 bits (1 hex digit)
            rest >>= 0x4; // right shift the rest to remove the last 4 bits (hex digit)
        } else {
            d = rest % base;
            rest /= base;
        }

        if (d < 0xA) {
            dest[pos++] = d | 0x30; // convert decimal digits to char by OR with 0x30, as 0-9 in ASCII are 0x30-0x39
        } else {
            dest[pos++] = (d | 0x30) + 0x7; // convert decimal digits to char by OR with 0x30 and adding 7, as A-F in ASCII are 0x41-0x46 
        }

    } while (rest > 0);

    if (negative) {
        dest[pos++] = 0x2D;
    }

    // leading 0's for binary, leading_zeros is 0 for other bases
    for (int i = 0; i < leading_zeros; i++) {
        dest[pos++] = 0x30;
    }

    dest[pos] = 0;

    not_strreverse(dest);
}

void int_to_dec(int num, char *dest)
{
    int_to_base_x(num, dest, 0xA);
}

void int_to_bin(int num, char *dest)
{
    int_to_base_x(num, dest, 0x2);
}

void int_to_hex(int num, char *dest)
{
    int_to_base_x(num, dest, 0x10);
}

void int_to_oct(int num, char *dest)
{
    int_to_base_x(num, dest, 0x8);
}