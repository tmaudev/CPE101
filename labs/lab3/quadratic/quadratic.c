/* quadratic.c
 *
 * Tyler Mau
 * Sept. 28, 2012
 *
 * Description: Determines if roots of a quadratic equation are real or imaginary.
 *
 */

/* Directives */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "checkit.h"

/* Function Prototypes */
double Root1(double a, double b, double c, double d);
double Root2(double a, double b, double c, double d);
double Discriminant(double a, double b, double c);
int real_roots(double d);
void test_cases(double a, double b, double d);

/* Main Function */
int main()
{
   
   double a, b, c, d, s, s2, b2, root1, root2;
   int r;

   printf("\nEnter coefficients of quadratic equation: ");
   scanf("%lf %lf %lf", &a, &b, &c);
   d = Discriminant(a,b,c);
   
   r = real_roots(d);   
   if (r == 0)
   {
      printf("\nYour roots are imaginary.\n\nResults:\n");
      d = d * (double)-1;
      
      s = sqrt(d)/(2*a);
      s2 = fabs(s);
      b2 = -b/(2*a);

      if (s >= 0)
      {
         printf("\nRoot 1: %.1lf + %.1lfi\n", b2, s);
         printf("Root 2: %.1lf - %.1lfi\n\n", b2, s); 
      }
      else
      {
         printf("\nRoot 1: %.1lf - %.1lfi\n", b2, s2);
         printf("Root 2: %.1lf + %.1lfi\n\n", b2, s2);
      }
   }
   else
   {
      root1 = Root1(a,b,c,d);
      root2 = Root2(a,b,c,d);
      printf("\nYour roots are real.\n\nResults:\n");
      if (root1 == root2)
      {
         printf("\nRepeated Root Value: %.1lf\n\n", root1);
      }
      else
      {
         printf("\nRoot 1: %.1lf\n", root1);
         printf("Root 2: %.1lf\n\n", root2);
      }
   }

   test_cases(a,b,d);

   return 0;

}

/* Computes First Quadratic Root */
double Root1(double a, double b, double c, double d)
{

   double x1;
   x1 = (-b + sqrt(d)) / (2*a);
   return x1;

}

/* Computes Second Quadratic Root */
double Root2(double a, double b, double c, double d)
{

   double x2;
   x2 = (-b - sqrt(d)) / (2*a);
   return x2;

}

/* Computes the Discriminant of the Quadratic */
double Discriminant(double a, double b, double c)
{

   double discriminant;
   discriminant = b*b - 4*a*c;
   return discriminant;

}

/* Identifies Real Imaginary Roots */
int real_roots(double d)
{

   if (d < 0)
   {
      return 0;
   }
   else
   {
      return 1;
   }

}

/* Test Case Function */
void test_cases(double a, double b, double d)
{

   /* Checks if certain values are correct. */
   checkit_double(sqrt(d), 31);
   checkit_double(-b - sqrt(d), -42);
   checkit_double(-b + sqrt(d), 20);

}
