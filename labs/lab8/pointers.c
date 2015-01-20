/* pointers.c
 *
 * Tyler Mau
 * November 27, 2012
 *
 */

/* Directives */
#include<stdio.h>
#include<stdlib.h>

/* Function Prototypes */
void numberInfo(int size, int *array, int *odd, int *even, int *over100);

/* Main Function */
int main()
{
   int array[10] = {4,5,12,100,4,-90,101,200,3,46}, numOdd = 0, numEven = 0, numOver100 = 0;
   int *even, *odd, *over100;
   
   even = &numEven;
   odd = &numOdd;
   over100 = &numOver100;
   numberInfo(10,array,odd,even,over100);
   
   printf("\nNumber of Evens: %i\n", numEven);
   printf("Number of Odds: %i\n", numOdd);
   printf("Numbers Over 100: %i\n\n", numOver100);
   
   return 0;
}

void numberInfo(int size, int *array, int *odd, int *even, int *over100)
{
   int i;
   
   for(i=0; i<size; i++)
   {
      if(array[i] % 2 == 0)
      {
         *even += 1;
      }
      else
      {
         *odd += 1;
      }
      
      if(array[i] > 100)
      {
         *over100 += 1;
      }
   }
}
