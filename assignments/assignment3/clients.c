/* clients.c
 *
 * Tyler Mau
 * October 29, 2012
 *
 * Description: Reads in up to 100 clients and prints sorted data based on user input choice.
 *
 */

/* Directives */
#include <stdio.h>
#include <stdlib.h>
#include "checkit.h"
#include <string.h>

/* Structures */
struct Client
{
   char name[60];
   double bmi;
   int fitlvl;
};

/* Function Prototypes */
void print_clients(int numclients, struct Client *cli);
void sort_name(int numclients, struct Client *cli);
void sort_fitlvl(int numclients, struct Client *cli);
void filter(int numclients, struct Client *cli, int min, int max);
void search(int numclients, struct Client *cli, char *str);

/* Main Function */
int main()
{
   /* Create Menu to Print */
   char menu[150] = "********MENU********\n"
                    "(n)ame\n"
                    "(l)evel of fitness\n"
                    "(f)ilter\n"
                    "(s)earch\n"
                    "(q)uit\n"
                    "********************\n"
                    "Enter Sorting Operation: ";
   char choice, *n, str[60];
   int clientnum, done = 1, i = 0, min, max;
   struct Client cli[100];
   
   /* Prompt User for Client Number Input */
   printf("\nEnter Number of Clients: ");
   scanf("%i%*c", &clientnum);

   /* Prompts user for client input. RETURN x2 will stop reading in data. */
   printf("\nEnter Client Information Below:\n");

   /* Start Reading In Clients (Up to 100) */
   while(i < 100)
   {      
      /* Stops Reading When Number of Clients Reached */
      if(i == clientnum)
      {
         break;
      }

      /* Gets Client Name */
      fgets(cli[i].name, 60, stdin);

      /* Removes Return Character from Name String */
      if((n=strchr(cli[i].name, '\n')) != NULL)
      {
         *n = '\0';
      }

      /* Gets BMI */
      scanf("%lf*c", &cli[i].bmi);

      /* Gets Fitness Level */
      scanf("%i%*c", &cli[i].fitlvl);
      i++;
   }

   /* Starts Menu Loop */
   while(done != 0)
   {
      /* Prints Menu and Takes User Input */
      printf("\n%s", menu);   
      scanf("%c%*c", &choice);

      /* Switch Calls Functions Based on User Input */
      switch(choice)
      {
         case 'n':
            /* Calls Name Function and Prints Results */
            sort_name(i, cli);
            print_clients(i,cli);
            break;
         case 'l':
            /* Calls Fitness Level Function and Prints Results */
            sort_fitlvl(i,cli);
            print_clients(i,cli);
            break;
         case 'f':
            /* Prompts User for Fitness Level Min and Max */
            printf("\nEnter the lower fitness level: ");
            scanf("%i%*c", &min);
            printf("Enter the upper fitness level: ");
            scanf("%i%*c", &max);
            /* Calls Filter Function and Prints Results */
            filter(i,cli,min,max);
            printf("\n\n");
            break;
         case 's':
            /* Prompts User for Client Prefix */
            printf("\nEnter the prefix for the client: ");
            fgets(str, 60, stdin);
            /* Calls Search Function and Prints Results */
            search(i,cli,str);
            printf("\n\n");
            break;
         case 'q': 
            /* Quits Menu */
            printf("\nDone.\n\n");  
            done = 0;
            break;
         default:
            /* Notifies User If Invalid Choice Entered */
            printf("\nInvalid Choice.\n");
            break;
      }
   }

   return 0;
}

/* Print Function Prints Clients */
void print_clients(int numclients, struct Client *cli)
{
   int j = 0;

   /* Loop Prints Clients Based on Parameters */
   for(j=0; j<numclients; j++)
   {
      printf("\n%s -- BMI %.1lf -- Fitness Level %i", cli[j].name, cli[j].bmi, cli[j].fitlvl);
   }
   printf("\n\n");
}

/* Sort Function Sorts Clients Alphabetically */
void sort_name(int numclients, struct Client *cli)
{
   int i = 0, j = 0, k = 0;
   struct Client temp[1];

   /* Loops Through All Clients */
   for(i=0; i<numclients; i++)
   {
      /* Loop to Compare Each Client to the Others */
      for(j=i+1; j<numclients; j++)
      {
         /* Loop Compares Each Letter of Clients Names */
         for(k=0; k<strlen(cli[i].name); k++)
         {
            /* Swaps Client Location in Structure Array Based on Name (Alphabetically) */
            if(cli[i].name[k] > cli[j].name[k])
            {
               temp[0] = cli[i];
               cli[i] = cli[j];
               cli[j] = temp[0];
               break;
            }
            else if(cli[i].name[k] < cli[j].name[k])
            {
               break;
            }
         }
      }
   }
}

/* Fitness Level Function Sorts Clients Based on Fitness Level */
void sort_fitlvl(int numclients, struct Client *cli)
{
   int i = 0, j = 0;
   struct Client temp[1];

   /* Loops Through All Clients */
   for(i=0; i<numclients; i++)
   {
      /* Loop Compares Each Letter of Clients Names */
      for(j=i+1; j<numclients; j++)
      {
         /* Swaps Client Location in Structure Array Based on Fitness Level */
         if(cli[i].fitlvl < cli[j].fitlvl)
         {
            temp[0] = cli[i];
            cli[i] = cli[j];
            cli[j] = temp[0];
         }
      }
   }
}

/* Filter Function Finds Clients With Fitness Levels Within Specified Range */
void filter(int numclients, struct Client *cli, int min, int max)
{
   int i = 0, test = 0;;

   /* Loops Through All Clients */
   for(i=0; i<numclients; i++)
   {
      /* Prints Clients Within Fitness Level Range */
      if(cli[i].fitlvl <= max && cli[i].fitlvl >= min)
      {
         printf("\n%s -- BMI %.1lf -- Fitness Level %i", cli[i].name, cli[i].bmi, cli[i].fitlvl);
         test = 1;
      }
   }
   /* Variable Checks If Any Results Are Found */
   if(test != 1)
   {
      printf("\nNo Match Found.");
   }
}

/* Search Function Displays Clients with Names That Start With Specified Prefix */
void search(int numclients, struct Client *cli, char *str)
{
   int i = 0, j = 0, test = 0, test2 = 0;

   /* Loops Through All Clients */
   for(i=0; i<numclients; i++)
   {
      test = 0;
      /* Loop Checks Each Letter of Client */
      for(j=0; j<strlen(str)-1; j++)
      {
         /* Assign Variable Value If Name Matches Prefix */
         if(cli[i].name[j] == str[j])
         {
             test = 1;
         }
         else
         {
            test = 0;
            break;
         }
      }

      /* Prints Clients That Past Test */
      if(test == 1)
      {
         printf("\n%s -- BMI %.1lf -- Fitness Level %i", cli[i].name, cli[i].bmi, cli[i].fitlvl);
         test2 = 1;
      }
   }
   
   if(test2 == 0)
   {
      printf("\nNo Match Found.");
   }
}
