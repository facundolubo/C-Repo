#include <stdio.h>

int main () {
	char str[] = "hello world";
	puts(str);
	/* puts add a newline at the end 
	 * it is a safe function (not as gets)
	 * */
	puts(str);
	fputs(str, stdout);
	// that's not the behavior of fputs
	fputs(str, stdout);
	return 0;
}
