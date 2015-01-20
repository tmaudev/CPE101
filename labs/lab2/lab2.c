/* lab2.c
 *
 * Tyler  Mau
 * Sept. 26, 2012
 *
 * Computes the area and perimeter of a rectangle and the area and circumference of a circle.
 *
 */

/* Directives */
#include <stdio.h>
#include <stdlib.h>
#include "checkit.h"

/* Function Prototypes */
int AreaOfRectangle(int height, int width);
int PerimeterOfRectangle(int height, int width);
void test_cases(int h, int w, double r);
double AreaOfCircle(double radius);
double CircumferenceOfCircle(double radius);

/* Define pi */
double pi = 3.14159265;

/* Main Function */
int main()
{
   int h, w, aor, p; 
   double c, aoc, r;

   /* Prompt User For Input and Scan */
   printf("\nEnter an integer height and width: ");
   scanf("%i %i", &h, &w);
   printf("Enter a radius: ");
   scanf("%lf", &r);

   aor = AreaOfRectangle(h, w);
   p = PerimeterOfRectangle(h, w);
   aoc = AreaOfCircle(r);
   c = CircumferenceOfCircle(r);

   /* Print Results */
   printf("\nArea of Rectangle = %i\nPerimeter of Rectangle = %i\n", aor, p);
   printf("Area of Circle = %.2lf\nCircumference of Circle = %.2lf\n\n", aoc, c);
   
   /* Call Test Case Function */
   test_cases(h, w, r);

   return 0;
}

/* Compute Area Of Rectangle */
int AreaOfRectangle(int height, int width)
{
   
   int area;
   area = height * width;
   return area;

}

/*Compute Perimeter Of Rectangle */
int PerimeterOfRectangle(int height, int width)
{

   int perimeter;
   perimeter = (height * 2) + (width * 2);
   return perimeter;

}

/* Computer Area Of Circle */
double AreaOfCircle(double radius)
{

   double area;
   area = pi * radius * radius;
   return area;
  
}

/* Computer Circumference Of Circle */
double CircumferenceOfCircle(double radius)
{

   double circumference;
   circumference = 2 * pi * radius;
   return circumference;

}

/* Test Case Function */
void test_cases(int h, int w, double r)
{ 

   checkit_int(h,5);
   checkit_int(w,4);
   checkit_int(((h*2)+(w*2)), 18);
   checkit_double(r, 4.5);
   checkit_double((pi*r*r), 63.617251);

}
