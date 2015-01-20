/* battleship.c
 * 
 * Tyler Mau
 * November 5, 2012
 *
 * Description:
 *
 * Battleship game.
 * Displays game board and interacts with user.
 * User inputs spot on board and H or M will be displayed.
 *
 */

/* Directives */
#include "battleship.h"

/* Main Function */
int main()
{
   /* Variable Declarations */
   int ship_num = 0, i = 0, ship_size[5] = {2,3,3,4,5}, score = 0, index[2], scorecalc = 0;
   double scoreadj;
   struct Ship ships[5];
   struct Score scores[5];
   char board[10][10], ship_locations[10][10], cont = 'Y', name[60], *n;
   
   /* Welcome String */
   char welcome[509] =  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~WELCOME TO~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                        "--------------------------------------------------------------------------\n"
                        "                                                                          \n"
                        " * * *      *    * * *  * * *  *      * * *   * *  *   *  * * *  * * *    \n"
                        " *    *    * *     *      *    *      *      *     *   *    *    *    *   \n"
                        " * * *    *   *    *      *    *      * * *    *   * * *    *    * * *    \n";
   char welcome2[509] = " *    *  * * * *   *      *    *      *         *  *   *    *    *        \n"
                        " * * *  *       *  *      *    * * *  * * *  * *   *   *  * * *  *        \n"
                        "                                                                          \n"
                        "--------------------------------------------------------------------------\n"
                        "                                ___                                       \n"
                        "                                | |___     .__                            \n";
   char welcome3[509] = "                              .--_____|..---/                             \n"
                        "                          .__.|-........ ' /                              \n"
                        "~~~~~~~~~~~~~~~~~~~~~~~~~~|_______________/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                        "                                                                          \n";
   printf("%s", welcome);
   printf("%s", welcome2);
   printf("%s", welcome3);
   
   /* While Loop Allows User to Replay */
   while(cont == 'Y')
   {
      ship_num = 0;
      while(ship_num <= 0 || ship_num > 5)
      {
         printf("\nHow many ships do you want to destroy?\n");
         printf("Enter Number of Ships (1-5): ");
         scanf("%i%*c", &ship_num);
         
         if(ship_num <= 0 || ship_num > 5)
         {
            printf("\nInvalid Number. Try again.\n");
         }
      }

      printf("\n\n");
      
      /* Define Ships */
      for(i=0; i<ship_num; i++)
      {
         ships[i].ID = '1' + i;
         ships[i].size = ship_size[i];
         ships[i].hits = 0;
      }
      strcpy(ships[0].name, "Patrol Boat");
      strcpy(ships[1].name, "Destroyer");
      strcpy(ships[2].name, "Submarine");
      strcpy(ships[3].name, "Battleship");
      strcpy(ships[4].name, "Aircraft Carrier");
      
      /* Create Board */
      create_board(board);
      
      /* Randomizes and Places Ships */
      place_ships(ship_locations, ship_num, ship_size, ships);
      
      /* Notifies User Game is Ready */
      printf("Game Ready. Ship sizes: ");

      i = 0;
      
      /* Prints Ship Sizes for User */
      if(ship_num == 1)
      {
         printf("%i", ship_size[i]);
      }
      else
      {
         while(i < ship_num-1)
         {
            if(ship_num == 2)
            {
               printf("%i ", ship_size[i]);
            }
            else
            {
               printf("%i, ", ship_size[i]);
            }
            i++;
         }
         printf("and %i", ship_size[i]);
      }
   
      /* Creates Score Adjustment */
      i = 0;
      scorecalc = 0;
      scoreadj = 0;
      while(i < ship_num)
      {
         scorecalc += ship_size[i];
         i++;
      }
      scoreadj = (double)scorecalc/100;
      
      /* Prints Board and Starts Gameplay */
      print_board(ship_locations);
      score = play_game(ship_locations, board, ships, ship_num);
      
      /* Displays Score and Prompts User For Information */
      printf("Shots Fired: %i\n", 100-score);
      
      /* Adjusts Score Based On Ships */
      score = (int)(score - (score * scoreadj));
      
      printf("Enter Your Name For Ranking: ");
      fgets(name,60,stdin);

      /* Removes Newline Character From Name String */
      if((n=strchr(name, '\n')) != NULL)
      {
         *n = '\0';
      }

      /* Prints Scores */
      printf("\nHere are the Rankings:\n");

      readscores(score, scores, index);
      scoreoutput(score, name, scores, index);      

      printf("\n");

      cont = 'X';
      
      /* Checks If User Wants To Play Again */
      while(cont == 'X')
      {
         printf("Would you like to play again? (Y or N): ");
         scanf("%c%*c", &cont);
         
         if(cont == 'Y')
         {
            break;
         }
         else if(cont == 'N')
         {
            printf("\nI guess you couldn't take the heat! See you again soon...\n\n");
            break;
         }
         else
         {
            printf("\nWhat? You can't read? Choose from 'Y' or 'N'.\n");
            cont = 'X';
         }
      }
   }
   return 0;
}

/* Creates Visual Board For User */
void create_board(char board[10][10])
{
   int i = 0, j = 0;
   
   /* Creates Initial Board Map */
   for(i=0; i<10; i++)
   {
      for(j=0; j<10; j++)
      {
         board[i][j] = '~';
      }
   }
   
}

/* Prints Board */
void print_board(char board[10][10])
{
   int i = 0, j = 0;
   
   /* Prints Letters */
   printf("\n\n     ");
   for(j=1; j<11; j++)
   {
      printf("%c   ", 'A' + (j-1));
   }
   
   for(i=0; i<10; i++)
   {
      printf("\n");
      
      /* Prints Numbers */
      if(i < 9)
      {
         printf("%i    ", i + 1);
      }
      else
      {
         printf("%i   ", i + 1);
      }
      
      /* Prints Board Map */
      for(j=0; j<10; j++)
      {
         printf("%c   ", board[i][j]);
      }
   }
   printf("\n");
}

/* Randomizes and Places Ships */
void place_ships(char ship_locations[10][10], int ship_num, int ship_size[5], struct Ship ships[])
{
   int i, j, d, x = 0, t = 0, test = 0;
   /* Creates 2-D Arrays to Identify Ship Locations */
   
   for(i=0; i<10; i++)
   {
      for(j=0; j<10; j++)
      {  
         ship_locations[i][j] = '~';
      }
   }
   
   /* Seeds Random Based on Internal Time */
   srand((unsigned int)time(NULL));
   
   while(x < ship_num)
   {
      /* Chooses Random Location on Board */
      i = rand() % 10;
      j = rand() % 10;
      /* Chooses Random Direction */
      d = rand() % 4 + 1;
      
      t = 0;
      test = 0;
      
      /* For the Following Code:
       * For each random location and direction, checks if ship will fit in that spot.
       * If ship doesn't fit, randomize another location and direction and try again.
       * Also checks if a ship already exists in any of the spots the new ship is tried.
       */
      
      /* Direction: Up */
      if(d == 1)
      {
         /* Checks If Ship Will Fit In Location */
         if(i >= ship_size[x]-1)
         {
            /* Checks If Another Ship Exists In Locations */
            while(t < ship_size[x])
            {
               if(ship_locations[i-t][j] != '~')
               {
                  test = 1;
                  break;
               }
               t++;
            }
            /* If Ship Fits In Location, Place Ship */
            if(test != 1)
            {
               for(t=0; t<ship_size[x]; t++)
               {
                  ship_locations[i-t][j] = '1' + x;
               }
               x++;
            }
         }
      }
      /* Direction: Right */
      else if(d == 2)
      {
         /* Checks If Ship Will Fit In Location */
         if(ship_size[x] <= (10-j))
         {
            /* Checks If Another Ship Exists In Locations */
            while(t < ship_size[x])
            {
               if(ship_locations[i][j+t] != '~')
               {
                  test = 1;
                  break;
               }
               t++;
            }
            /* If Ship Fits In Location, Place Ship */
            if(test != 1)
            {
               for(t=0; t<ship_size[x]; t++)
               {
                  ship_locations[i][j+t] = '1' + x;
               }
               x++;
            }
         }
      }
      /* Direction: Down */
      else if(d == 3)
      {
         /* Checks If Ship Will Fit In Location */
         if(ship_size[x] <= (10-i))
         {
            /* Checks If Another Ship Exists In Locations */
            while(t < ship_size[x])
            {
               if(ship_locations[i+t][j] != '~')
               {
                  test = 1;
                  break;
               }
               t++;
            }
            /* If Ship Fits In Location, Place Ship */
            if(test != 1)
            {
               for(t=0; t<ship_size[x]; t++)
               {
                  ship_locations[i+t][j] = '1' + x;
               }
               x++;
            }
         }
      }
      /* Direction: Left */
      else
      {
         /* Checks If Ship Will Fit In Location */
         if(j >= ship_size[x]-1)
         {
            /* Checks If Another Ship Exists In Locations */
            while(t < ship_size[x])
            {
               if(ship_locations[i][j-t] != '~')
               {
                  test = 1;
                  break;
               }
               t++;
            }
            /* If Ship Fits In Location, Place Ship */
            if(test != 1)
            {
               for(t=0; t<ship_size[x]; t++)
               {
                  ship_locations[i][j-t] = '1' + x;
               }
               x++;
            }
         }
      }
   }
}

/* Gameplay Function */
int play_game(char ship_locations[10][10], char board[10][10], struct Ship ships[], int ship_num)
{
   int finish = 0, i = 0, j = 0, n = 0, t = 0, test = 0, score = 0;
   char guess;
   
   /* Loops Until User Wins Game */
   while(finish != 1)
   {
      /* Adds 1 to Score for Each Attempt */
      score++;
      
      /* Prompts User for Guess */
      printf("\nAIM & FIRE! (Enter Your Guess): ");
      scanf("%c%i%*c", &guess, &i);
      
      /* Checks for Invalid Input */
      if(guess > 'J' || guess < 'A' || i < 1 || i > 10)
      {
         printf("\nInvalid Choice. Try Again. (Choice is Case Sensitive)");
         print_board(ship_locations);
      }
      else
      {
         /* Changes Guess Characters Into Location Integers */
         i = i - 1;
         j = (int)(guess - 65);
         
         /* Checks if Ship in Guess Location */
         if(ship_locations[i][j] != '~')
         {
            n = (int)ship_locations[i][j] - 48;
            ships[n-1].hits++;
            board[i][j] = 'X';
            print_board(ship_locations);
            printf("\nHIT!");
            
            /* Checks if Ship is Sunk */
            if(ships[n-1].hits == ships[n-1].size)
            {
               printf(" You sunk my %s!", ships[n-1].name);
               for(t=0; t<ship_num; t++)
               {
                  if(ships[t].hits == ships[t].size)
                  {
                     test++;
                  }
                  else
                  {
                     t = 0;
                     test = 0;
                     break;
                  }
               }
               
               /* If All Ships Are Sunk, User Wins */
               if(test == ship_num)
               {
                  printf("\n\nCongratulations. You have...defeated me...\n");
                  finish = 1;
                  break;
               }
            }
         }
         /* Displays Miss if Ship Is Not in Guess Location */
         else
         {
            board[i][j] = 'O';
            print_board(ship_locations);
            printf("\nMISS!");
         }
      }
   }
   if(score > 100)
   {
      score = 100;
   }
   score = 100 - score;
   return score;
}

/* Function Reads Current Scores */
void readscores(int score, struct Score scores[5], int index[2])
{
   FILE * scorefile = fopen("scorefile.txt", "r");
   char tempscore[3];
   int i = 0, len;
   index[0] = -1;

   /* Reads Scores and Puts Into Struct Array */
   while((i<5) && (fgets(scores[i].name,60,scorefile) != NULL))
   {
      len = strlen(scores[i].name);
      strncpy(tempscore,&scores[i].name[len-3],2);
      /* Converts String Score Into Integer */
      scores[i].score = (tempscore[0]-48)*10 + (tempscore[1]-48);

      /* Determines Location For New Score */
      if(score <= scores[i].score)
      {
         index[0] = i;
      }
      i++;
   }
   index[1] = i;
   fclose(scorefile);
}

/* Function Places New Score Into Score File */
void scoreoutput(int score, char *name, struct Score scores[5], int index[2])
{
   FILE * scorefile = fopen("scorefile.txt", "w");
   int i = 0, test = 0;

   /* Prints Higher Scores */
   for(i=0; i<=index[0]; i++)
   {
      fprintf(scorefile,"%s", scores[i].name);
      printf("%s", scores[i].name);
   }
   
   if(index[0] < 4)
   {
      /* Prints New Score */
      fprintf(scorefile,"%s %02i\n",name,score);
      printf("%s %02i\n",name,score);
   }
   else
   {
     test = 1;
   }

   /* Prints Lower Scores */
   while((i < 4) && (i < index[1]))
   {
      fprintf(scorefile,"%s", scores[i].name);
      printf("%s", scores[i].name);
      i++;
   }

   if(test == 1)
   {
      printf("\nSorry, I guess you weren't good enough to make it in the rankings...\n");
   }

   fclose(scorefile);
}
