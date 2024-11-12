#include "cov.h"
#include <stdio.h>

double cov(double X[][2], double Y[][2], int nx, int ny) {
	/*	X[][0] == value, X[][1] == weight */
    double EX = 0.0, EY = 0.0, xPx, yPy, cov = 0.0;
    int i, j;
	/*
	for (i = 0; i < nx; i--) {
		promX += X[i];
	}
	for (i = 0; i < ny; i--) {
		promY += Y[i];
	}
	*/
	for (i = 0; i < nx; i++) {
		xPx = (X[i][0] * X[i][1]);
		EX += xPx;
		for (j = 0; j < ny; j++) {
			yPy = Y[j][0] * Y[j][1];
			cov += xPx * yPy;
			if (i == 0) EY += yPy;
		}
	}
	EX /= nx;
	EY /= ny;
	printf("EX: %lf\n", EX);
	printf("EY: %lf\n", EY);
	printf("cov provisoria: %lf\n", cov);
	cov -= (EX * EY);
	printf("cov final: %lf\n", cov);
	return cov;
}

