#include <stdio.h>

/* receives two strings t, s, returns s with t concatenated */

/* Receives two strings t and s, concatenates t to the end of s */
void my_strcat(char *s, char *t) {
    // Move `s` to point to the null terminator of the original string
    while (*s) s++;
    // Now, `s` is at the end; start copying `t` here
    while (*s++ = *t++);
}

int main() {
    char s[100] = "Hello, ";  // Destination string with extra space
    char t[] = "world!";      // Source string to concatenate

    my_strcat(s, t);
    printf("Concatenated string: %s\n", s);  // Display result

    return 0;
}
