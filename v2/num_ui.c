#include<stdio.h>
#include "numconv1.h"
#include "num_ui.h"

int main()
{
    char from_choice = ' ';
    char to_choice = ' ';
    while(from_choice != '0' && to_choice != '0'){
        print_menu();
        from_choice = get_choice(0);
        to_choice = get_choice(1);
        char value[50] = "";
        int value_in_int = get_value_in_int(from_choice, value);
        char result[50] = "";
        convert_int_to_string(to_choice, value_in_int, result);
        print_result(from_choice, to_choice, value, result);
    }

    return 0;
}

void print_menu()
{
    printf("------------------------------------\n");
    printf("1. Decimal\n");
    printf("2. Binary\n");
    printf("3. Hexadecimal\n");
    printf("4. Octal\n");
    printf("0. exit\n");
    printf("------------------------------------\n");
}

char get_choice(int to)
{
    
    if(to){
        printf("Choose base to convert to: ");
    } else {
        printf("Choose base to convert from: ");
    }
    char choice;
    scanf(" %c", &choice);
    return choice;
}
void get_value(char *str, const char *type)
{
    printf("Enter %s number to convert: ", type);
    scanf(" %s", str);
}

int get_value_in_int(char choice, char *value)
{
    int int_value;
    switch (choice)
    {
    case '1':
        get_value(value, "decimal");
        int_value = dec_to_int(value);
        return int_value;
    case '2':
        get_value(value, "binary");
        int_value = bin_to_int(value);
        return int_value;
    case '3':
        get_value(value, "hexadecimal");
        int_value = hex_to_int(value);
        return int_value;
    case '4':
        get_value(value, "octal");
        int_value = oct_to_int(value);
        return int_value;
    default:
        printf("error\n");
        return 0;
    }
}

void convert_int_to_string(char choice, int value, char *dest)
{
    switch (choice)
    {
    case '1':
        int_to_dec(value, dest);
        break;
    case '2':
        int_to_bin(value, dest);
        break;
    case '3':
        int_to_hex(value, dest);
        break;
    case '4':
        int_to_oct(value, dest);
        break;
    default:
        printf("error\n");
        break;
    }
}

void print_result(char from, char to, char *from_value, char *to_value)
{
    const char *from_type = get_type_from_choice(from);
    const char *to_type = get_type_from_choice(to);
    
    printf("------------------------------------\n");
    printf("%s in %s = %s in %s\n", from_value, from_type, to_value, to_type);
    printf("------------------------------------\n");
}

const char *get_type_from_choice(char choice)
{
    switch (choice)
    {
    case '1':
        return "decimal";
    case '2':
        return "binary";
    case '3':
        return "hexadecimal";
    case '4':
        return "octal";
    default:
        return "";
    }
}