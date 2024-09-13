#include <stdio.h>
#include "numconv1.h"

// Test functions for _to_int functions
void test_base_x_to_int() {
    int a = base_x_to_int(10, "123");
    int b = base_x_to_int(10, "-123");
    int c = base_x_to_int(2, "1101");
    int d = base_x_to_int(16, "1A3");
    int e = base_x_to_int(16, "1a3");
    printf("%d, %d, %d, %d, %d\n", a, b, c, d, e);
}

// Test functions for int_to_ functions
void test_int_to_base_x() {
    char a[50] = "";
    char b[50] = "";
    char c[50] = "";
    char d[50] = "";
    int_to_base_x(123123123, a, 10);
    int_to_base_x(-123, b, 10);
    int_to_base_x(4095, c, 2);
    int_to_base_x(419121242, d, 16);
    printf("%s, %s, %s, %s\n", a, b, c, d);
}

int main() {
    test_base_x_to_int();
    test_int_to_base_x();
    return 0;
}