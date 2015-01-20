/* sum.c
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
int sum(int *array, int size);
void test_cases(int *array, int size);

/* Main Function */
int main()
{
   /* Test Array */
   int size, sumarray;
   int array[10] = {1,2,3,4,5,6,7,8,9,0};
   
   size = 10;
   sumarray = sum(array,10);
   
   test_cases(array,size);
   
   return 0;
}

int sum(int *array, int size)
{
   int i, s=0;
   for(i=0; i<size; i++)
   {
      s = s + array[i];
   }
   return s;
}

void test_cases(int *array, int size)
{
   int a[] = {4,8,15,16,23,42};
   int size1 = 6;

   /* Test Sample Array */
   checkit_int(sum(array,size), 45);

   checkit_int(sum(a,size1), 108);
}
