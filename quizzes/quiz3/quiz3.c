/* quiz3.c
 *
 * Tyler Mau
 * November 30, 2012
 *
 */

#include "quiz3.h"

/* Main Function */
int main()
{
   struct Point points[11];
   struct Point userpoint;
   int testFile = 0, testPoint = 0, i = 0;

   testFile = read_points(points);
   
   printf("\nGreetings, user. Ten points have just been read from a file.\nPlease enter another: ");
   scanf("%i %i %i", &userpoint.x, &userpoint.y, &userpoint.z);
 
   if(testFile == 1)
   {
      testPoint = checkPoint(points, userpoint);
      
      if(testPoint == 1)
      {
         printf("The array is now as follows:\n");
         for(i=0; i<11; i++)
         {
            printf("%i %i %i\n", points[i].x, points[i].y, points[i].z);
         }
      }
      else
      {
         printf("The array is as follows:\n");
         for(i=0; i<10; i++)
         {
            printf("%i %i %i\n", points[i].x, points[i].y, points[i].z);
         }
      }
   }
   else
   {
      printf("\nCould not read file.\n");
   }   
   
   printf("\n");
   return 0;
}

int read_points(struct Point points[11])
{
   FILE * pointFile = fopen("points.txt", "r");
   int i = 0;

   for(i=0; i<10; i++)
   {
      fscanf(pointFile, "%i %i %i", &points[i].x, &points[i].y, &points[i].z);
   }

   if(pointFile == NULL)
   {
      return 0;
   }
   
   return 1;
}

int checkPoint(struct Point points[11], struct Point userpoint)
{
   int i = 0;
   for(i=0; i<10; i++)
   {
      if((userpoint.x == points[i].x) && (userpoint.y == points[i].y) && (userpoint.z == points[i].z))
      {
         printf("\nThat point was already in the file.\n");
         return 0;
      }
   }
   points[10].x = userpoint.x;
   points[10].y = userpoint.y;
   points[10].z = userpoint.z;
   printf("\nThat point was not in the file. It has been added into the array.\n");
  
   return 1;
}
