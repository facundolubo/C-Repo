#include <stdio.h>
#include <string.h>

int main() {
	char str1[100];
	char input[100];
    printf("Enter two strings\n");
	scanf("%s", str1);
	strcat(str1, " & ");
	scanf("%s", input);
	strcat(str1, input);
	printf("%s \n", str1);
	return 0;
}
