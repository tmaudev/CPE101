/* ccard.c
 *
 * Tyler Mau
 * October 12, 2012
 *
 */

/* Directives */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "checkit.h"

/* Function Prototypes */
void swap(int *a);
int luhn(int *a);
void cctype(int *acopy);
void test_cases();

/* Main Function */
int main()
{
   int a[16], acopy[16], i, cd;

   /* Prompts User for Input */
   printf("\nPlease enter the 16-digit credit card number: ");

   /* Sets Each Digit As An Array Element */
   for(i=0; i<16; i++)
   {
      a[i] = getchar() - 48;
   }

   /* Creates a Copy of Array for Checking Card Type */
   for(i=0; i<16; i++)
   {
      acopy[i] = a[i];
   }

   /* Calls Swap and Luhn Functions to Determine Check Digit */
   swap(a);
   cd = luhn(a);

   /* Prints Check Digit Results */
   if(a[15] == cd)
   {
      printf("The check digit is valid.\n");
   }
   else
   {
      printf("The check digit is invalid! It should be %i.\n", cd);
   }

   /* Calls Function to Determine Card Type */
   cctype(acopy);

   /* Calls Test Case Function */
   test_cases();

   return 0;
}

/* Swaps Each Pair of Digits Except Last 2 */
void swap(int *a)
{
   int temp,i;

   for(i=0; i<14; i=i+2)
   {
      temp = a[i];
      a[i] = a[i+1];
      a[i+1] = temp;
   }
}

/* Luhn Function Determines Check Digit */
int luhn(int *a)
{
   int i, oddtotal = 0, eventotal = 0, total, checkdigit;

   /* Triples Odds & Squares Evens */
   for(i=0; i<15; i++)
   {
      if(i%2 == 0)
      {
         a[i] = pow(a[i],2);
         /* Adds Even Values */
         eventotal = eventotal + a[i];
      }
      else
      {
         a[i] = a[i] * 3;
         /* Subtracts 12 If Value > 12 */
         if(a[i] > 12)
         {
            a[i] = a[i] - 12;
         }
         /* Adds Odd Values */
         oddtotal = oddtotal + a[i];
      }
   }

   /* Totals Evens and Odds */
   total = eventotal + oddtotal;

   /* Determines Check Digit */
   if(total%10 == 0)
   {
      checkdigit = 0;
   }
   else
   {
      checkdigit = 10 - (total%10);
   }

   return checkdigit;
}

/* Determines Card Type Based on Card Prefix */
void cctype(int *acopy)
{
   if(acopy[0] == 3)
   {
      if((acopy[1] == 6) || (acopy[1] == 8))
      {
         printf("Credit card type: Diner's Club/Carte Blanche.\n\n");
      }
      else if(acopy[1] == 0)
      {
         if((acopy[2] >= 0) && (acopy[2] <= 5))
         {
            printf("Credit card type: Diner's Club/Carte Blanche.\n\n");
         }
      }
      else if((acopy[1] == 4) || (acopy[1] == 7))
      {
         printf("Credit card type: American Express.\n\n");
      }
      else
      {
         printf("Credit card type: Unknown Type.\n\n");
      }
   }
   else if(acopy[0] == 4)
   {
      printf("Credit card type: Visa.\n\n");
   }
   else if((acopy[0] == 5) && (acopy[1] >= 1) && (acopy[1] <= 5))
   {
      printf("Credit card type: Master Card.\n\n");
   }
   else if((acopy[0] == 6) && (acopy[1] == 1) && (acopy[2] == 0) && (acopy[3] == 2))
   {
      printf("Credit card type: Discover.\n\n");
   }
   else
   {
      printf("Credit card type: Unknown Type.\n\n");
   }
}

/* Test Case Function */
void test_cases()
{
   /* Test Credit Card Array */
   int atest[16] = {1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2};
   int c;

   /* Calls Swap Function */
   swap(atest);

   /* Checks Swap */
   /* First 2 Values */
   checkit_int(atest[0], 2);
   checkit_int(atest[1], 1);
   /* Last 2 Values Should Not Change */
   checkit_int(atest[14], 3);
   checkit_int(atest[15], 2);

   /* Calls Luhn Function (Outputs Check Digit) */
   c = luhn(atest);

   /* Checks Check Digit */
   checkit_int(c, 4);
}
