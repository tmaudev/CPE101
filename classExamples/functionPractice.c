/*
 * File: functionPractice.c
 * Programmer: Tyler Mau
 * Description: Practicing Functions
 * Sept. 24, 2012
 */

#include <stdio.h>
#include <stdlib.h>

int addOne(int num);
int subtractOne(int num);
void greeting();
int perimeterRec(int w, int h);

int main()
{
   int num, incNum, decNum, w, h, pr;

   printf("\n");
   greeting();

   printf("Enter an Integer: ");
   scanf("%i", &num);

   incNum = addOne(num);
   decNum = subtractOne(num);
   
   printf("Integer + 1 = %i\nInteger - 1 = %i\n", incNum, decNum);

   printf("\nEnter an Integer Width: ");
   scanf("%i", &w);
   printf("Enter an Integer Height: ");
   scanf("%i", &h);
   pr = perimeterRec(w,h);
   printf("Perimeter of Rectangle = %i\n\n", pr);
   
   return 0;

}

int addOne(int num)
{

   int numPlusOne;
   numPlusOne = num + 1;
   return numPlusOne;

}

int subtractOne(int num)
{

   return num - 1;

}

void greeting()
{

   printf("Hello!\n");

}

int perimeterRec(int w, int h)
{

   int perimeter;
   perimeter = (w * 2) + (h * 2);
   return perimeter;

}
