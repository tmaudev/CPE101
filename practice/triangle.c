/* Practice #3 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
   char c = '%';
   int num = 5, i = 0, j = 0;
   
   for(i = 0; i < num; i++)
   {
      j = 0;
      while(j <= i)
      {
         printf("%c", c);
         j++;
      }
      printf("\n");
   }
   return FALSE;
}
