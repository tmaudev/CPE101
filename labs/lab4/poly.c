/* poly.c
 *
 * Tyler Mau
 * October 8, 2012
 *
 */

/* Directives */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "checkit.h"

/* Function Prototypes */
void poly_sub2(double *poly1, double *poly2, double *result);
void poly_mult2(double *poly1, double *poly2, double *result);
void test_cases();

/* Main Function */
int main()
{
   double poly1[3], poly2[3], result[3], mresult[5];
   
   printf("\nEnter Coefficients of Polynomial 1: ");
   scanf("%lf %lf %lf", &poly1[2], &poly1[1], &poly1[0]);
   printf("Enter Coefficients of Polynomial 2: ");
   scanf("%lf %lf %lf", &poly2[2], &poly2[1], &poly2[0]);

   poly_sub2(poly1, poly2, result);
   poly_mult2(poly1, poly2, mresult);
   printf("\nDifference: %.2lfx^2 + %.2lfx + %.2lf\n", result[2], result[1], result[0]);
   printf("Product: %.2lfx^4 + %.2lfx^3 + %.2lfx^2 + %.2lfx + %.2lf\n\n", mresult[4], mresult[3], mresult[2], mresult[1], mresult[0]);

   test_cases();

   return 0;
}

void poly_sub2(double *poly1, double *poly2, double *result)
{
   result[0] = poly1[0] - poly2[0];
   result[1] = poly1[1] - poly2[1];
   result[2] = poly1[2] - poly2[2];
}

void poly_mult2(double *poly1, double *poly2, double *mresult)
{
   mresult[0] = poly1[0] * poly2[0];
   mresult[1] = (poly1[0] * poly2[1]) + (poly1[1] * poly2[0]);
   mresult[2] = (poly1[0] * poly2[2]) + (poly1[1] * poly2[1]) + (poly1[2] * poly2[0]);
   mresult[3] = (poly1[1] * poly2[2]) + (poly1[2] * poly1[1]);
   mresult[4] = poly1[2] * poly2[2];
}

void test_cases()
{

   /* Tests Pass for Identical Polynomials */
   double poly1[3] = {2,2,2};
   double poly2[3] = {2,2,2};
   double result[3];
   double mresult[5];

   poly_sub2(poly1, poly2, result);
   poly_mult2(poly1, poly2, mresult);

   checkit_double(result[0], 0);
   checkit_double(result[1], 0);
   checkit_double(result[2], 0);

   /* Tests will pass if all coefficients of both polynomials are 2. */
   checkit_double(mresult[0], 4);
   checkit_double(mresult[1], 8);
   checkit_double(mresult[2], 12);
   checkit_double(mresult[3], 8);
   checkit_double(mresult[4], 4);

}
