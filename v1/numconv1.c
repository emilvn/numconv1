#include "../lib/string/not_string.h"
#include<stdio.h>
// For alle konverteringsfunktioner gælder at de modtager en streng der enten benyttes som input eller output.
// De arbejder kun med heltal, og kun med integers. 
// Integers er som udgangspunkt signed, men kun decimal (titalssystemet) viser negative tal, de øvrige viser to’s komplement udgaven af tallet.

int base_x_to_int(int base, char *str)
{
    int val = 0;
    int length = not_strlen(str);
    int negative = 0;

    if(str[0] == '-' && base == 10){
            negative = 1;
    }

    for (int i = negative; i < length; i++) {
        val *= base;
        if(base <= 10){
            val += str[i] - '0';
        } else if(base <= 16) {
            if(str[i] >= '0' && str[i] <= '9'){
                val += str[i] - '0';
            } else if(str[i] >= 'A' && str[i] <= 'F'){
                val += str[i] - ('A' - 10);
            } else if(str[i] >= 'a' && str[i] <= 'f'){
                val += str[i] - ('a' - 10);
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
    int rest = num;
    int pos = 0;
    int negative = 0;

    if (num < 0 && base == 10) {
        negative = 1;
        rest = -rest;
    }

     // calc amount of digits for binary
    int num_digits = 0;
    int tmp = rest;
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
        if(pos != 0 && (((base == 2 || base == 16) && pos % 5 == 4) || (base == 8 && pos % 4 == 3))) {
            dest[pos++] = ' ';
        } else if(base == 10 && pos % 4 == 3){
            dest[pos++] = ',';
        }
        int d = rest % base;
        if (d < 10) {
            dest[pos++] = '0' + d;
        } else {
            dest[pos++] = 'A' + (d - 10);
        }
        rest /= base;

    } while (rest > 0);
    if(negative) {
        dest[pos++] = '-';
    }

    // leading 0's for binary, leading_zeros is 0 for other bases
    for (int i = 0; i < leading_zeros; i++) {
        dest[pos++] = '0';
        if ((pos % 5) == 4) {
            dest[pos++] = ' ';
        }
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