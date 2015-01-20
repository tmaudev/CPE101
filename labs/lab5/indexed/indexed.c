/* indexed.c
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
int index(int *a1, int *a2, int length1, int length2);
void test_cases(int *a1, int *a2, int length1, int length2);

/* Main Function */
int main()
{
   /* Declare Sample Arrays */
   int a1[] = {1,9,3,2,4,6};
   int a2[] = {1,2,5,1};
   int length1 = 6, length2 = 4, s;

   /* Call Index Function */
   s = index(a1,a2,length1,length2);
   
   test_cases(a1,a2,length1,length2);

   return 0;
}

/* Determines Sum */
int index(int *a1, int *a2, int length1, int length2)
{
   int i, sum=0;

   for(i=0; i<length2; i++)
   {
      if(a2[i]<length1)
      {
         sum = sum + a1[a2[i]];
      }
   }
   return sum;
}

void test_cases(int *a1, int *a2, int length1, int length2)
{
   
   int a3[] = {1,20,3,4,5,6,7,8,9,0,1,2,3};
   int a4[] = {5,4,3,2,1,4,5,6,7,10};
   int length3 = 13, length4 = 10;

   /* Checks Sum of Sample Array (Main) */
   checkit_int(index(a1,a2,length1,length2), 27);

   /* Another Test */
   checkit_int(index(a3,a4,length3,length4), 65);
}
