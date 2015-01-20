/* rot_13_line.c
 * 
 * Tyler Mau
 * October 19, 2012
 *
 */

/* Directives */
#include <stdio.h>
#include <stdlib.h>
#include "checkit.h"
#include <string.h>

/* Function Prototypes */
void rotline(char *str);
void test_cases();

/* Main Function */
int main()
{
   char str[100];

   printf("\nEnter a String of Characters (CTRL-D to Quit): ");

   while(fgets(str,100,stdin) != NULL)
   {
      rotline(str);
      printf("\n%s", str);
      printf("\nEnter Another String (CTRL-D to Quit): ");
   }
   printf("\n\nDone.\n\n");
   test_cases();
   return 0;
}

void rotline(char *str)
{
   int i = 0;
   while(str[i] != '\0')
   {
      if(((str[i] >= 'A') && (str[i] <= 'Z')) || ((str[i] >= 'a') && (str[i] <= 'z')))
      {
         if(((str[i] <= 'M') && (str[i] >= 'A')) || ((str[i] <= 'm') && (str[i] >= 'a')))
         {
            str[i] = str[i] + 13;
         }
         else
         {
            str[i] = str[i] - 13;
         }
         i++;
      }
      else
      {
         i++;
      }
   }
}

void test_cases()
{
   char str[100] = "Hello";
   rotline(str);
   checkit_char(str[0], 'U');
   checkit_char(str[1], 'r');
   checkit_char(str[2], 'y');
   checkit_char(str[3], 'y');
   checkit_char(str[4], 'b');
}
