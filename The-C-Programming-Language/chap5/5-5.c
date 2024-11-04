#include <stdio.h>
#include <string.h>

// Function declarations
char * my_strncpy(char *s, const char *t, int n);
char *my_strcat(char *s, const char *t, int n);
int my_strcmp(const char *s, const char *t, int n);

char * my_strncpy(char *s, const char *t, int n) {
	char * start = s;
	while (n-- > 0 && (*s++ = *t++));
    if (n >= 0 | *s) {
        *s = '\0';
    }
	return start;
}

char * my_strcat(char *s, const char *t, int n) {
    char * start = s;
	while (*s) s++; // Move s to the end of the string
    while (n-- > 0 && (*s++ = *t++)); // Concatenate n characters from t to s
    *s = '\0'; // Null-terminate the result
	return start;
}

int my_strcmp(const char *s, const char *t, int n) {
    while (n-- > 0 && *s && *t) {
        if (*s != *t) {
            return *s - *t; // Return difference if characters are not equal
        }
        s++;
        t++;
    }
    return n < 0 ? 0 : *s - *t; // Return difference considering the length
}

int main() {
    char dest[100]; // Buffer for destination strings
    char src1[100]; // Buffer for source strings
    char src2[100]; // Another source string for strcat and strcmp
    int choice, n;

    // Menu loop
    while (1) {
        printf("Choose an option:\n");
        printf("1. strcpy (copy string)\n");
        printf("2. strcat (concatenate string)\n");
        printf("3. strcmp (compare strings)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) {
            break; // Exit the loop if user chooses to exit
        }

        printf("Enter the first string: ");
        scanf(" %[^\n]%*c", src1); // Read string with spaces

        if (choice == 1) {
            printf("Enter number of characters to copy: ");
            scanf("%d", &n);
            printf("Result of strcpy: %s\n", my_strncpy(dest, src1, n));
        } else if (choice == 2) {
            printf("Enter the second string to concatenate: ");
            scanf(" %[^\n]%*c", src2); // Read second string
            printf("Enter number of characters to concatenate: ");
            scanf("%d", &n);
            my_strncpy(dest, src1, 20); // Initialize dest with src1
            my_strcat(dest, src2, n);
            printf("Result of strcat: %s\n", dest);
        } else if (choice == 3) {
            printf("Enter the second string to compare: ");
            scanf(" %[^\n]%*c", src2); // Read second string
            printf("Enter number of characters to compare: ");
            scanf("%d", &n);
            int cmp_result = my_strcmp(src1, src2, n);
            if (cmp_result == 0) {
                printf("The strings are equal up to %d characters.\n", n);
            } else if (cmp_result < 0) {
                printf("The first string is less than the second string.\n");
            } else {
                printf("The first string is greater than the second string.\n");
            }
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

