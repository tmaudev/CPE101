/* encrypt.c
 *
 * Tyler Mau
 * November 7, 2012
 *
 * Description: Encrypts Files
 *
 */

/* Directives */
#include <stdio.h>
#include <stdlib.h>

/* Function Prototypes */
char rot13(char c);

/* Main Function */
int main()
{
   FILE * inputfile = fopen("unencrypted.txt", "r");
   FILE * outputfile = fopen("encrypted.txt", "w");
   char c, r;

   while((fscanf(inputfile, "%c", &c)) != EOF)
   {
      if(((c <= 'Z') && (c >= 'A')) || ((c <= 'z') && (c >= 'a')))
      {
         r = rot13(c);
         fprintf(outputfile, "%c", r);
      }
      else
      {
         fprintf(outputfile, "%c", c);
      }
   }
   
   fclose(inputfile);
   fclose(outputfile);

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
