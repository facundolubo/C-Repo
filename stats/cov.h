/* Implement covariance of X and Y <COV(X,Y)> 
 * given a joint probability mass function of X and Y <PMF(X,Y)>
 *
 * Input:
 * X[]: random variable X represented in onedimensional array
 * nx: size of X
 *
 * Y[]: onedimensional array
 * ny: size of Y
 *
 * W[]: onedimensional array
 * 
 * optional:
 * EX: pointer to double, NULL otherwise
 * EY: pointer to double, NULL otherwise
 *
 * Output:
 * cov: covariance
 * also print preliminary values like:
 * 
 *
 * */

#ifndef COV_H
#define COV_H

double cov(double X[], int nx, double Y[], int ny, double W[], double *EX double *EY);

#endif

