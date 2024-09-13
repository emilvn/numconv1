int is_digit(char c)
{
    if((c >= '0' && c <= '9') || c == '-'){
        return 1;
    }
    return 0;
}

int is_bin_digit(char c)
{
    if(c == '0' || c == '1'){
        return 1;
    }
    return 0;
}

int is_hex_digit(char c)
{
    if((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f')){
        return 1;
    }
    return 0;
}

int is_oct_digit(char c)
{
    if(c >= '0' && c <= '7'){
        return 1;
    }
    return 0;
}