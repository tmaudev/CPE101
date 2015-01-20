/* rot_13_char.c
 *
 * Tyler Mau
 * October 17, 2012
 *
 */

/* Directives */
#include <stdio.h>
#include <stdlib.h>
#include "checkit.h"

/* Function Prototypes */
char rot13(char c);
void test_cases();

/* Main Function */
int main()
{
   char c, r;

   /* Prompt User for Input */
   printf("\nPlease Enter a Character (CTRL-D to Quit): ");
   c = getchar();

   /* Asks for Character Input Until Given CTRL-D */
   while(c != EOF)
   {   
      if(c != '\n')
      {
         if(((c <= 'Z') && (c >= 'A')) || ((c <= 'z') && (c >= 'a')))
         {
            r = rot13(c);
            printf("ROT-13 Character: %c\n", r);
         }
         else
         {
            printf("Incorrect Character Input.\n");
         }
         
         printf("\nEnter Another Character (CTRL-D to Quit): ");
      }
      c = getchar();
      
   }

   printf("\nDone.\n\n");
   test_cases();

   return 0;
}

/* ROT-13 Function */
char rot13(char c)
{
   char r;
   if(((c <= 'M') && (c >= 'A')) || ((c <= 'm') && (c >= 'a')))
   {
      r = c + 13;
   }
   else
   {
      r = c - 13;
   }
   return r;
}

void test_cases()
{
   /* Tests Rot-13 Function */
   checkit_char(rot13('a'), 'n');
   checkit_char(rot13('n'), 'a');
   checkit_char(rot13('b'), 'o');
   checkit_char(rot13('l'), 'y');
}
