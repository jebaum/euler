/* A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
 *
 * A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.
 *
 * As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.
 *
 * Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
 */

#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

int main()
{
  // according to wolfram alpha the real upper limit is 20161, not 28123
  unsigned int i,entries=0,j,sum=0;
  int* abundants = malloc(10000 * sizeof(int));
  char checked[20162];

  for (i=0; i<20162; ++i)
    checked[i] = 'O';

  for (i=12; i<20162; ++i)
    if ( sumOfDivisors(i)-i > i)
      abundants[entries++] = i;
  abundants = realloc(abundants, entries);

  for (i=0; i<entries; ++i)
    for (j=i; j<entries; ++j)
      if (abundants[i] + abundants[j] < 20162)
        checked[abundants[i] + abundants[j]] = 'X';

  for (i = 1; i<20162; ++i)
    if (checked[i] == 'O')
      sum += i;
  printf("sum is %u\n", sum);
}
