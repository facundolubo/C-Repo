#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* getch and getche doesn't be used because aren't on standar library */
int main () {
	char text[100];
	//int c2 = getc(stdin);
	//int c3 = fgetc(stdin);
	printf("Type a line of text: ");
	scanf("%s", text);
	printf("The line you typed is: %s\n", text);
	return 0;
}

