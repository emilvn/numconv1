int not_strlen(const char *s)
{
    int i = 0;
    while(s[i] != '\0'){
        i++;
    }
    return i;
}

int not_strcmp(char *s1, char *s2) {
    int length = not_strlen(s1);
    for (int i = 0; i < length; i++) {
        if(s1[i] != s2[i]){
            return s1 - s2;
        }
    }
    return 0;
}

char* not_strcpy(char* dest, const char* src)
{
    int src_len = not_strlen(src);
    for (int i = 0; i < src_len; i++) {
        dest[i] = src[i];
    }
    return dest;
}

char* not_strcat(char *dest, const char *src)
{
    int dest_len = not_strlen(dest);
    int src_len = not_strlen(src);

    for (int i = dest_len; i < dest_len + src_len; i ++){
        dest[i] = src[i - dest_len];
    }
    return dest;
}

void not_strreverse(char *str)
{
    int first = 0;
    int last = not_strlen(str) - 1;
    char tmp;

    while ( first < last){
        tmp = str[first];
        str[first] = str[last];
        str[last] = tmp;

        first++;
        last--;
    }
}