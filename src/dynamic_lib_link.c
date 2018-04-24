char *convert_to_lower_case(char *str) {
    int i = 0;
    while (str[i] != 0) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
        }
        i++;
    }
    return str;
}

char *convert_to_upper_case(char *str) {
    int i = 0;
    while (str[i] != 0) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
        i++;
    }
    return str;
}
