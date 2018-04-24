int number_of_letter(char *str, char c) {
    int i = 0;
    int counter = 0;
    while (str[i] != 0) {
        if (str[i] == c) {
            counter++;
        }
        i++;
    }
    return counter;
}
