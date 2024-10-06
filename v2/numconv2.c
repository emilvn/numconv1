#include "../lib/string/not_string.h"
#include<stdio.h>

int base_x_to_int(int base, char *str)
{
    int val = 0;
    int length = not_strlen(str);
    int negative = 0;

    if(str[0] == '-' && base == 10){
            negative = 1;
    }

    for (int i = negative; i < length; i++) {
        if (base == 2) {
            val <<= 1; // each step we left shift by 1 bit(* 2) as we go from 1s to 2s to 4s etc.
            val |= str[i] & 0xF; // mask with F to get the integer value of the char(0 or 1) and add it to val by OR
        } else if (base == 16) {
            val <<= 4; // each step we left shift by 4 bits(* 16) as we go from 1s to 16s to 256s etc.
            if(str[i] >= '0' && str[i] <= '9'){ // if the char is a decimal number
                val |= str[i] & 0xF; // mask with F to get the integer value of the char(0-9) and add it to val by OR
            } else {
                val |= (str[i] & 0xF) + 9; // if the char is a lette we mask as above and add 9 to get the decimal value of the letter(10-15)
            }
        } else {
            val *= base;
            if(base <= 10){
                val += str[i] - '0';
            }
        }
    }

    if(negative == 1 && base == 10){
        val = -val;
    }

    return val;
}

int dec_to_int(char *str)
{
    return base_x_to_int(10, str);
}

int bin_to_int(char* str)
{
    return base_x_to_int(2, str);
}

int hex_to_int(char* str)
{
    return base_x_to_int(16, str);
}

int oct_to_int(char* str)
{
    return base_x_to_int(8, str);
}

void int_to_base_x(int num, char *dest, int base)
{
    int pos = 0;
    int negative = 0;
    unsigned int rest = num;

    if (num < 0 && base == 10) {
        negative = 1;
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
    if (base == 2) {
        leading_zeros = (4 - (num_digits % 4)) % 4;
    }

    do {
        if (pos != 0 && (((base == 2 || base == 16) && pos % 5 == 4) || (base == 8 && pos % 4 == 3))) {
            dest[pos++] = ' ';
        } else if (base == 10 && pos % 4 == 3) {
            dest[pos++] = ',';
        }

        int d;
        if (base == 2) {
            d = rest & 1; // mask with 1 to get the last bit
            rest >>= 1; // right shift the rest to remove the last digit
        } else if (base == 16) {
            d = rest & 0xF; // mask with 4 to get the last 4 bits (1 hex digit)
            rest >>= 4; // right shift the rest to remove the last 4 bits (hex digit)
        } else {
            d = rest % base;
            rest /= base;
        }

        if (d < 10) {
            dest[pos++] = '0' + d; // convert decimal digits to char
        } else {
            dest[pos++] = 'A' + (d - 10); // convert hex digits to char
        }

    } while (rest > 0);

    if (negative) {
        dest[pos++] = '-';
    }

    // leading 0's for binary, leading_zeros is 0 for other bases
    for (int i = 0; i < leading_zeros; i++) {
        dest[pos++] = '0';
    }

    dest[pos] = '\0';

    not_strreverse(dest);
}

void int_to_dec(int num, char *dest)
{
    int_to_base_x(num, dest, 10);
}

void int_to_bin(int num, char *dest)
{
    int_to_base_x(num, dest, 2);
}

void int_to_hex(int num, char *dest)
{
    int_to_base_x(num, dest, 16);
}

void int_to_oct(int num, char *dest)
{
    int_to_base_x(num, dest, 8);
}