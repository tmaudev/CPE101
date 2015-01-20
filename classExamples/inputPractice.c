/* inputPractice.c
 *
 * Tyler Mau
 * Sept. 28, 2012
 *
 * Description: Take user's age as input and calculate his/her age in dog years.
 *
 * */

#include <stdio.h>
#include <stdlib.h>

/* Function Prototypes */
double AgeToDogYears(double age);

/* Main Function */
int main()
{
   
   double age, dogyears;
   printf("\nEnter your age: ");
   scanf("%lf", &age);
   dogyears = AgeToDogYears(age);
   printf("\nYour age in dog years is %.1lf.\n\n", dogyears);

   return 0;

}

/* Converts Age To Dog Years */
double AgeToDogYears(double age)
{

   double dogyears;
   dogyears = age * (double)7;
   return dogyears;

}
