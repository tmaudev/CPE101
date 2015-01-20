/* arrayPractice.c
 *
 * Tyler Mau
 * October 24, 2012
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
   int array[5];
   int i;
   printf("Enter Array: ");


   for(i=0; i<5; i++) 
   {
      scanf("%i", &array[i]);
   }

   printf("\n\n");

   i = 0;
   while(i < 5)
   {
      printf("%i", array[i]);
      i++;
   }
   printf("\n\n");

   return 0;
}
