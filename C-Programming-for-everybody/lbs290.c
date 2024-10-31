#include <string.h>
#include <stdio.h>

void process (char line[]) {
	int count = 0;
	printf("%s\n", line);
	do {
		if (line[count] == ' ') {line[count] = '-';}
	}
	while (line[count++]);
	count--;
	printf("Count=%d\n", count);
	if (count >= 9) printf("The ninth caracter is: %c\n", line[9]);
	printf("%s\n", line);
}

int main() {
	char line[1000];
	void process();
	strcpy(line, "Hi there and welcome to LBS290");
	process(line);
	strcpy(line, "I love C");
	process(line);
	return 0;
}
