/* battleship.h
 * 
 * Tyler Mau
 * November 9, 2012
 *
 */
#ifndef Battleship_Header_h
#define Battleship_Header_h
#endif

/* Directives */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Structures */
struct Ship
{
   int ID;
   int size;
   int hits;
   char name[81];
};

struct Score
{
   char name[60];
   int score;
};

/* Function Prototypes */
void create_board(char board[10][10]);
void print_board(char board[10][10]);
void place_ships(char ship_locations[10][10], int ship_num, int ship_size[5], struct Ship ships[]);
int play_game(char ship_locations[10][10], char board[10][10], struct Ship ships[], int ship_num);
void readscores(int score, struct Score scores[100], int index[2]);
void scoreoutput(int score, char *name, struct Score scores[100], int index[2]);
