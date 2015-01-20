/* Header File For quiz3.c */

/* Directives */
#include <stdio.h>
#include <stdlib.h>

/* Structures */
struct Point
{
   int x;
   int y;
   int z;
};

/* Function Prototypes */
int read_points(struct Point points[11]);
int checkPoint(struct Point points[11], struct Point userpoint);
