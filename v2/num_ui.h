void print_menu();
char get_choice(int to);
void get_value(char *str, const char *type);
int get_value_in_int(char choice, char *value);
void convert_int_to_string(char choice, int value, char *dest);
void print_result(char from, char to, char *from_value, char *to_value);
const char *get_type_from_choice(char choice);