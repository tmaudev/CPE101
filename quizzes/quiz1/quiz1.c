/* Quiz 1
 * 
 * Tyler Mau
 * October 3, 2012
 *
 */

/* Directives */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "checkit.h"

/* Function Declarations */
double f(double x);
double radius_to_sa(double r);
void test_cases(double r);

double pi = 3.1415;

/* Main Function */
int main()
{

   double x, r, y, surfaceArea;

   printf("\nEnter a value for X: ");
   scanf("%lf", &x);
   printf("Enter the radius of a sphere: ");
   scanf("%lf", &r);

   surfaceArea = radius_to_sa(r);
   y = f(x);

   printf("\nFor f(x) = 4x^2 + 1x + 3,\nf(%.2lf) = %.2lf", x, y);
   printf("\n\nSurface Area of Sphere(Radius = %.2lf) = %.2lf\n\n", r, surfaceArea);

   test_cases(r);
   return 0;
}

/* Computes Function */
double f(double x)
{
   double y;

   y = 4 * pow(x,2) + x + 3;
   
   return y;
}

/* Computes Surface Area of Sphere */
double radius_to_sa(double r)
{
   double sa;

   sa = ((double)4/(double)3) * pi * pow(r,3);
   

   return sa;
}

/* Test Case Function */
void test_cases(double r)
{
   /* Checks Power Function */
   checkit_double(pow(r,3), r*r*r);

   /* Checks for Integer Truncation */ 
   checkit_double((double)4/(double)3, 1.3333333)
}
