/* quiz2_1.c
 *
 * Tyler Mau
 * October 26, 2012
 *
 * Description: Determines the number of integers in an array that are less than the value given.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "checkit.h"

#define size 8

int count(int *a, int max);
void test_cases();

int main()
{
   int a[size], i, max, num;
   printf("\nEnter 8 Integers: ");
   
   for(i=0; i<size; i++)
   {
      scanf("%i", &a[i]);
   }

   printf("Enter an Integer Value: ");
   scanf("%i", &max);

   num = count(a,max);

   printf("\nThe number of values less than %i in your array were %i.\n\n", max, num); 

   test_cases();

   return 0;
}

int count(int *a, int max)
{
   int i, n = 0;
   for(i=0; i<size; i++)
   {
      if(a[i] < max)
      {
         n = n + 1;
      }
   }
   return n;
}

void test_cases()
{
   int testarray[size] = {1,4,3,6,7,3,9,2};
   int max = 3;
   checkit_int(count(testarray,max), 2);
}
