/* routes.c
 *
 * Tyler Mau
 * October 5, 2012
 *
 */

/* Directives */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "checkit.h"
#define pi 3.1415

/* Function Prototypes */
double displacement(double x1, double y1, double x2, double y2);
double distance(double *a);
double direction(double *a);
void test_cases(double *a, double dist, double disp, double deg);

/* Main Function */
int main()
{

   /* Variable Declarations */
   double dist, disp, deg;
   /* Creates Array for Coordinates */
   double c[6];

   /* Prompt for User Input */
   printf("\nPlease enter the starting x and y coordinates: ");
   scanf("%lf %lf", &c[0], &c[1]);
   printf("Please enter the second x and y coordinates:: ");
   scanf("%lf %lf", &c[2], &c[3]);
   printf("Please enter the third x and y coordinates: ");
   scanf("%lf %lf", &c[4], &c[5]);
   
   /* Call Functions */
   dist = distance(c);
   disp = displacement(c[0],c[1],c[4],c[5]);
   deg = direction(c);

   /* Print Results */
   printf("\nThe displacement is: %.2lfm, at an angle of %.2lf degrees.\n", disp, deg);
   printf("The distance is: %.2lfm.\n\n", dist);

   /* Test Case Function */
   test_cases(c, dist, disp, deg);

   return 0;
}

/* Displacement Function */
double displacement(double x1, double y1, double x2, double y2)
{
   double d = sqrt(pow(x2-x1,2) + pow(y2-y1,2));
   return d;
}

/* Distance Function */
double distance(double *a)
{
   double d1, d2, total;

   d1 = displacement(a[0],a[1],a[2],a[3]);
   d2 = displacement(a[2],a[3],a[4],a[5]);

   total = d1 + d2;
   return total;
}

/* Displacement Angle */
double direction(double *a)
{
   double radAngle, degAngle;
   radAngle = atan((a[5]-a[1])/(a[4]-a[0]));
   degAngle = radAngle * (double)180 / pi;
   return degAngle;
}

/* Test Case Function */
void test_cases(double *a, double dist, double disp, double deg)
{
   /* Checks Types of Certain Values */
   checkit_double(a[0], a[0]);
   checkit_double(dist, dist);
   checkit_double(disp, disp);
   checkit_double(deg, deg);
} 
