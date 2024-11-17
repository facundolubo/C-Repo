#include "cov.h"
#include <stdio.h>

double cov(double X[], int nx, double Y[], int ny, double W[], double *EX double *EY);
    double xPx, yPy, cov = 0.0;
    int i, j;
	if (EX != NULL && EY != NULL) {
	}
	else {
	
	for (i = 0; i < nx; i++) {
		for (j = 0; j < ny; j++) {
			cov += (X[i] * Y[j] * W[j+i]);
		}
	}
	printf("EX: %lf\n", EX);
	printf("EY: %lf\n", EY);
	/*
	EX /= nx;
	EY /= ny;
	printf("uX: %lf\n", EX);
	printf("uY: %lf\n", EY);
	*/
	printf("cov provisoria: %lf\n", cov);
	cov -= (EX * EY);
	printf("cov final: %lf\n", cov);
	return cov;
}

