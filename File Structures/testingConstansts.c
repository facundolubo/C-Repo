#include <stdio.h>
#include <unistd.h>

int main () {
	printf("STDIN_FILENO = %d\nSTDOUT_FILENO = %d\nSTDERR_FILENO = %d\n", STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO);
	return 0;
}
