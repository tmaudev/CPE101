/* Tyler Mau          */
/* September 21, 2012 */
/* DataTypeExamples.c */

#include <stdio.h>

/* Defining Pi */
#define PI 3.14

int main()
{
   /* Define Character */
   char myChar = 'm';
   
   /* Define Integer */
   int myInt = 7;

   /* Define Double */
   double myDouble = 3.2;

   /* Print Characters, Integers, and Doubles */
   printf("My character is %c. My integer is %i. My double is %.1lf.\n", myChar, myInt, myDouble);
   printf("My integers are: %i %i %i \n", myInt, myInt + 1, myInt + 2);

   /* Change Double */
   myDouble = 8.07;

   /* Print New Double */
   printf("My double has changed. It is now: %.2lf \n", myDouble);

   return 0;

}
