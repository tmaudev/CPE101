/* pointers.c
 *
 * Tyler Mau
 * November 27, 2012
 *
 */

/* Directives */
#include <stdio.h>
#include <stdlib.h>

/* Function Prototypes */
void ones(int *myArray, int array_size);

/* Main Function */
int main()
{
   int myArray[50], i = 0;
   int size = 6;

   for(i=0; i<50; i++)
   {
      myArray[i] = i + 2;
   }

   printf("\n");
   for(i=0; i<50; i++)
   {
      printf("%i ", myArray[i]);
   }

   ones(myArray+8, size);

   printf("\n");
   for(i=0; i<50; i++)
   {
      printf("%i ", myArray[i]);
   }
   printf("\n\n");

   return 0;
}

void ones(int *myArray, int array_size)
{
   int i = 0;

   for(i=0; i<array_size; i++)
   {
      *(myArray+i) = 1;
   }
}
