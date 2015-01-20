/* subarray.c
 *
 * Tyler Mau
 * October 15, 2012
 *
 */

/* Directives */
#include <stdio.h>
#include <stdlib.h>
#include "checkit.h"

/* Function Prototypes */
void test_cases(int *a, int size, int start, int end);
int subarray(int *a, int size, int start, int end);

/* Main Function */
int main()
{
   /* Test Array */
   int a[10] = {1,2,3,4,5,6,7,8,9,0};
   int size = 10, sum;
   sum = subarray(a,size,3,6);

   test_cases(a,size,3,6);

   return 0;
}

int subarray(int *a, int size, int start, int end)
{
   int sum = 0, i = 0;
   if((start < size) && (end < size))
   { 
      for(i=start; i<=end; i++)
      {
         sum = sum + a[i];
      }
   }

   return sum;
}

/* Test Case Function */
void test_cases(int *a, int size, int start, int end)
{
   int a1[] = {4,8,15,16,23,42};
   int size1 = 6;

   /* Checks Test Array (Main) */
   checkit_int(subarray(a, size, start, end), 22);

   /* Another Test */
   checkit_int(subarray(a1, size1, 0, 5), 108);
}
