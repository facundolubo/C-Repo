#include <stdio.h>

int main () {
	char str[10];
	// gets(str);  warning: "gets.c:(.text+0x28): warning: the `gets' function is dangerous and should not be used"
	/* For example, if I write a string with more than 10 chars (in this example), i will overwrite the next cell of memory
	 *  you can try adding a variable that store the 11th char and print it
	 */
	 
	// gets_s(str, 10); This only works on windows i think
	
	/* fgets is the correct function to use
	 * If i try to print more than 10 i will get an error
	 * */
	fgets(str, 10, stdin);
	printf("You typed %s\n", str);
	return 0;
}


