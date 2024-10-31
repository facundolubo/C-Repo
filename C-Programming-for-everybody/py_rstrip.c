void py_rstrip(char inp[]) {
    int len = strlen(inp) - 1;

    while (len >= 0 && inp[len] == ' ') {
        len--;
    }

    inp[len + 1] = '\0';
}
