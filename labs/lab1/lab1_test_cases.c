/* Test cases example for lab 1.
 *
 * Tyler Mau
 * Sept. 24, 2012
*/

#include <stdio.h>
#include "checkit.h"

/*Returns an integer value one greater than the integer argument*/
int successor(int n)
{
   return n + 1;
}

/*Returns the square of the integer argument*/
int square(int n)
{
   return n * n;
}

/*Compares the argument values and checks whether or not they are equal.
 *If the values are equal, the test case passes. Otherwise they fail.
 *When the debug executable is run, the passed and failed test cases are displayed.
 *When the "run version" program is run, the test case results are not shown.
*/

void test_cases(void)
{
   checkit_int(successor(1), 2);
   checkit_int(successor(2), 3);
 
   /*Incorrect Test Case
   checkit_int(successor(-1), -2);
   */

   /*Fixed Test Case*/
   checkit_int(successor(-1), 0);

   /*Incorrect Test Case
   checkit_int(square(1), 2);
   */

   /*Fixed Test Case*/
   checkit_int(square(1), 1);

   checkit_int(square(2), 4);
   checkit_int(square(5), 25);

   /*Incorrect Test Cases
   checkit_double(2.7, 3.1);
   checkit_char('a', 'b');
   checkit_string("abc", "def");
   */

   /*Fixed Test Cases*/
   checkit_double(2.7, 2.7);
   checkit_char('a', 'a');
   checkit_string("abc", "abc");
}

int main(int argc, char **argv)
{
   test_cases();

   return 0;
}
