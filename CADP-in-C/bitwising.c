#include <stdio.h>


int switchOthers() {
    static struct {
        unsigned int value: 3;
    } threeBitVar = {0};
	threeBitVar.value = 1 << threeBitVar.value;
    if (threeBitVar.value == 0) {
		threeBitVar.value = 1 << threeBitVar.value;
	}
    return threeBitVar.value;
}

/*
int switchOthers() {
    static unsigned int value = 0; // Start with 2^0 (1)
    value = (1 << value) % 8; // Cycle through 0, 1, 2
    return  value;// Return 2^0, 2^1, or 2^2
}
*/
int main() {
    for (int i = 0; i < 15; ++i) {
        printf("Invocation %d: %d\n", i + 1, switchOthers());
    }
    return 0;
}
