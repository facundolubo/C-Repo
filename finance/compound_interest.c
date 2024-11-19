#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define E 2.718281828459045235360287471352662497757247093699959574966967627

long double ci(double amount, int r, int num, int time) {
    double rate = (double) r / 100;
    return (long double) amount * pow((1 + (rate / num)), (num * time));
}

long double cie(double amount, int r, int num, int time) {
    double rate = (double) r / 100;
    return (long double) amount * exp(rate * time);
}

long double ciE(double amount, int r, int num, int time) {
    double rate = (double) r / 100;
    return (long double) amount * pow(E, (rate * time));
}

int main(int argc, char *argv[]) {
    double amount = 0.0;
    int rate = 0, num = 0, time = 0;

    while (--argc && (*++argv)[0] == '-') {
        char c = *++argv[0];
        switch (c) {
            case 'a':
                amount = atof(argv[1]);
                argv++; argc--;
                break;
            case 'r':
                rate = atoi(argv[1]);
                argv++; argc--;
                break;
            case 'n':
                num = atoi(argv[1]);
                argv++; argc--;
                break;
            case 't':
                time = atoi(argv[1]);
                argv++; argc--;
                break;
            default:
                printf("Invalid argument. Valid ones: -a -r -t -n\n");
                return 1;
        }
    }

    if (argc > 0) {
        printf("Too many arguments. Exiting program.\n");
        return 1;
    } else {
        printf("Amount: %.2f\tRate: %d\tNumber of periods: %d\tTime in years: %d\n", amount, rate, num, time);
        printf("ci(): %.2Lf\n", ci(amount, rate, num, time));
        printf("cie(): %.2Lf\n", cie(amount, rate, num, time));
        printf("ciE(): %.2Lf\n", ciE(amount, rate, num, time));
    }

    return 0;
}

