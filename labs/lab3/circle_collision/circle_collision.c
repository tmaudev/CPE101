/* circle_collison.c
 * 
 * Tyler Mau
 * October 1, 2012
 *
 */

/* Directives */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "checkit.h"

/* Function Declarations */
int circle_collision_test(double x1, double x2, double y1, double y2, double r1, double r2);
void test_cases(double x1, double x2, double y1, double y2, double r1, double r2);

/* Main Function */
int main()
{

   double x1, x2, y1, y2, r1, r2;
   int cc;

   /* Prompt User for Circle Position and Radius */
   printf("\nEnter X and Y Coordinates for Circle 1: ");
   scanf("%lf %lf", &x1, &y1);
   printf("Enter a Radius for Circle 1: ");
   scanf("%lf", &r1);
   printf("\nEnter X and Y Coordinates for Circle 2: ");
   scanf("%lf %lf", &x2, &y2);
   printf("Enter a Radius for Circle 2: ");
   scanf("%lf", &r2);

   cc = circle_collision_test(x1, x2, y1, y2, r1, r2);

   if (cc == 0)
   {
      printf("\nYour circles did not collide.\n\n");
   }
   else
   {
      printf("\nYour circles collided.\n\n");
   }

   test_cases(x1, x2, y1, y2, r1, r2);

   return 0;  

}

/* Determines Circle Collision */
int circle_collision_test(double x1, double x2, double y1, double y2, double r1, double r2)
{

   double distance, max;

   /* Calculates Distance Between Circle Origins */
   distance = sqrt(pow((x2-x1),2) + pow((y2-y1),2));
   max = r1 + r2;

   if (max < distance)
   {
      return 0;
   }
   else
   {
      return 1;
   }
   
}

/* Test Case Function */
void test_cases(double x1, double x2, double y1, double y2, double r1, double r2)
{
   /* Checks collison of circles centered on x-axis */
   checkit_double(fabs(x2 - x1), r1 + r2);
   /* Checks collison of circles centered on y-axis */
   checkit_double(fabs(y2 - y1), r1 + r2);
}
