/*
 * Solver Practice
 */

#include <stdio.h>
#include <stdlib.h>

void fillZeroes(int aSum[25], int pos[25][25], int board[5][5], int numBoxes[25]);
void initialize(int aSum[25], int pos[25][25], int numBoxes[25]);
int isValid(int aSum[25], int pos[25][25], int board[5][5], int numBoxes[25]);

int main()
{
   int aSum[25], pos[25][25], numBoxes[25], board[5][5];
   fillZeroes(aSum,pos,board,numBoxes);
   initialize(aSum,pos,numBoxes);
   return 0;
}

void fillZeroes(int aSum[25], int pos[25][25], int board[5][5], int numBoxes[25])
{
   int i = 0, j = 0;
   for(i=0; i<25; i++)
   {
      aSum[i] = 0;
      numBoxes[i] = 0;
      for(j=0; j<25; j++)
      {
         pos[i][j] = 0;
      }
   }
   for(i=0; i<5; i++)
   {
      for(j=0; j<5; j++)
      {
         board[i][j] = 0;
      }
   }
}

/* Function initializes arrays and scans in from file */
void initialize(int aSum[25], int pos[25][25], int numBoxes[25])
{
   int num, i = 0, j = 0;
   FILE * file = fopen("test_input1", "r");

   fscanf(file, "%d", &num);

   for(i=0; i<num; i++)
   {
      fscanf(file, "%d %d", &aSum[i], &numBoxes[i]);

      for(j=0; j<numBoxes[i]; j++)
      {
         fscanf(file, "%d", &pos[i][j]);
      }
   }
   for(i=0; i<num; i++)
   {
      printf("%d ", aSum[i]);
      printf("%d ", numBoxes[i]);
      for(j=0; j<25; j++)
      {
         printf("%d ", pos[i][j]);
      }
      printf("\n");
   }
   fclose(file);
}

int isValid(int aSum[25], int pos[25][25], int board[5][5], int numBoxes[25])
{
   int i = 0, j = 0;

}
