/*
Exercise 5-13. Write the program tail, which prints the last n lines of its input.
By default, n is set to 10, let us say, but it can be changed by an optional argument so that

tail -n
prints the last n lines. The program should behave rationally no matter how unreasonable the
input or the value of n. Write the program so it makes the best use of available storage; lines
should be stored as in the sorting program of Section 5.6, not in a two-dimensional array of
fixed size.*/

/* this program could use a function like:
	char * strstr(cs, ct) {
		return pointer to first occurrence of string ct in cs, or NULL if not present 
	}
	that function is declared in <string.h>
*/
#include <stdio.h>

#define TRUE 1
#define FALSE 0

int getline();

int main(argc, *argv[]) {
	int param = except = number = found = 0;
	// first handle parameters passed with hyphens
	while (--argc > 0 && *++argv[0] == '-') {
		while (param = *++argv[0]) {
			switch (param) {
				case 'n':
					n_lines = 1;
					break;
				default:
					printf("Invalid case. -n is the only option available");
					argc = 0;
					found = -1;
					break;
			}
		}
	}
	return found;
}
