#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main () {
	char text[100];
	printf("Type a line of text here: ");
	fgets(text, 100, stdin);
	text[strlen(text) - 1] = '\0'; // = 0;
	int i;
	for (i=0; i <= strlen(text); i++) {
		printf("%d ", text[i]);
	}
	printf("\n");
	printf("You typed the line: %s", text);
	return 0;
}
