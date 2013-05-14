/* Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
 *
 * How many such routes are there through a 20×20 grid?
 */

#include <stdio.h>

int main()
{
  double i,num=1,denom=1;
  for (i=21; i<=40; ++i) // answer is 40 choose 20 according to pascal's triangle
  {
    num *= i;
    denom *= (i-20);
  }
  printf("%f\n", num/denom);
}
