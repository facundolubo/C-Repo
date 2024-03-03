#include <stdio.h>
#include <stdlib.h>

#define MAX_FACT 63

int main () {
    int n;
    printf("Enter the number of factorial to generate (up to %d): ", MAX_FACT);
    scanf("%d", &n);
    if (n > MAX_FACT || n <= 0) {
        printf("Invalid input. Please enter a number between 1 and %d\n", MAX_FACT);
        return 1;
    }

    long double fact = 1;
    for (int i = 2; i <= n; i++) {
    	fact = fact*i;
    }
	printf("Result: %.f\n", (double)fact);
    return 0;
}
