#include <stdio.h>

int htoi(char s[]) {
    int i, n;

    n = 0;
    for (i = 0; (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'F') || (s[i] >= 'a' && s[i] <= 'f'); ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            n = 16 * n + s[i] - '0';
        } else if (s[i] >= 'A' && s[i] <= 'F') {
            n = 16 * n + s[i] - 'A' + 10;
        } else if (s[i] >= 'a' && s[i] <= 'f') {
            n = 16 * n + s[i] - 'a' + 10;
        }
    }
    return n;
}

int main() {
    printf("htoi('becbd') = %d\n", htoi("becbd"));
    printf("htoi('f') = %d\n", htoi("f"));
    printf("htoi('F0') = %d\n", htoi("F0"));
    printf("htoi('12fab') = %d\n", htoi("12fab"));
    return 0;
}

