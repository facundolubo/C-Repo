/*
Exercise 5-13. Write the program tail, which prints the last n lines of its input.
By default, n is set to 10, let us say, but it can be changed by an optional argument so that

tail -n

prints the last n lines. The program should behave rationally no matter how unreasonable the
input or the value of n. Write the program so it makes the best use of available storage; lines
should be stored as in the sorting program of Section 5.6, not in a two-dimensional array of
fixed size.

I will also add an aditional argument '-d' so you can print lines in DESCENDENT order
*/

#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define ERROR -1
#define DEFAULT_N 10
#define MAXCHAR 1000
/* getline: read a line, return length */
int my_getline(char *line, int max) {
	if (fgets(line, max, stdin) == NULL) return 0;
	else return strlen(line);
}

int main(int argc, char * argv []) {
	char line[MAXCHAR];
	int n_lines, param, found, lineno, desc;
	param = found = lineno = 0;
	n_lines = DEFAULT_N;
	// first handle parameters passed with hyphens
	while (--argc > 0 && (*++argv)[0] == '-') {
		while (param = *++argv[0]) {
			switch (param) {
				case 'n':
					n_lines = atoi(*(argv[0]+1));
					break;
				case 'd':
					desc = TRUE;
					break;
				default:
					printf("Invalid case of %c. -n and -d are the only options available", param);
					argc = 0;
					found = ERROR;
					break;
			}
		}
	}

	// print the fucking lines. if desc, in descendt order
	while (my_getline(line, MAXCHAR) > 0) {
		lineno++;
		if (desc) {}
		else {printf("%d: %s", lineno, line);}
	}
	return found;
}
