/* quiz2_2.c
 *
 * Tyler Mau
 * October 26, 2012
 *
 * Description: Determines index where array values begin to descend.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define size 10

int indexnum(int *a);

int main()
{
   int a[size], i, index;

   printf("\nEnter 10 Integers that Ascend then Descend: ");

   for(i=0; i<size; i++)
   {
      scanf("%i", &a[i]);
   }

   index = indexnum(a);

   if(index != -1)
   {
      printf("\nThe numbers begin to descend at index %i.\n\n", index);
   }
   else
   {
      printf("\nThe numbers do not descend.\n\n");
   }

   return 0;
}

int indexnum(int *a)
{
   int i;

   for(i=0; i<size-1; i++)
   {
      if(a[i+1] < a[i])
      {
         return i + 1;
      }
   }

   /* Returns -1 if numbers do not start to descend. */
   return -1;
}
