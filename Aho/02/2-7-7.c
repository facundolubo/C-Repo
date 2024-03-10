/*
 * Make a recursive algo that takes an integer and produces the binary representation of that number. 
 * Low order bit first
 */

#include <stdio.h>
#include <stdlib.h>


int randomInt(int max, int min) {
    int range = max - min;
    return min + rand() % range;
}

void binaryRepresentation(int i) {
	if (i == 0) {
		printf("0");
	}
	else {
		printf("Actual number: %d\n", i);
		binaryRepresentation(i / 2);
		printf("%d", i % 2);         // Print the remainder (least significant bit)
	}
}

int main() {
	int i;
	printf("Enter an integer: ");
	scanf("%d", &i);
	binaryRepresentation(i);
	return 0;
}
