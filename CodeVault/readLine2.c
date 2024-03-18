#include <stdio.h>
/* getch and getche doesn't be used because aren't on standar library */
int main () {
	int c = getchar();
	//int c2 = getc(stdin);
	//int c3 = fgetc(stdin);
	printf("The char you typed is: %c\n", c);
	return 0;
}

