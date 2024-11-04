#include <stdio.h>
/* echo command-line arguments; 2nd version */
int main (int argc, char * argv[]) {
	//quiero saber cual es el primer argumento:
	printf("%s\n", *argv);
	//ahora si esto deberia ser lo que ejecuta el programa
	while (--argc > 0) printf((argc > 1) ? "%s " : "%s\n", *++argv);
	return 0;
}
