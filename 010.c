/* The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *
 * Find the sum of all the primes below two million.
 */

#include <stdio.h>
#include <math.h>
#define UPPER_LIMIT 2000000

// using index math described in 010_overview.pdf to optimize sieve
int main()
{
  char primes[(UPPER_LIMIT-1)/2];
  int i,j;
  unsigned long long sum = 2;

  for (i=1; i<(UPPER_LIMIT-1)/2; ++i) // initialize sieve
    primes[i] = 'p';

  for (i=1; i <= (sqrt(UPPER_LIMIT)-1)/2; ++i) // mark nonprimes with 'x'
  {
    if (primes[i] == 'p')
    {
      for (j=2*i*(i+1); j<(UPPER_LIMIT-1)/2; j+=(2*i+1))
      {
        primes[j] = 'x';
      }
    }
  }

  for (i=1; i<(UPPER_LIMIT-1)/2; ++i)
  {
    if (primes[i] == 'p')
      sum+=(2*i+1);
  }
  printf("sum is %llu\n", sum);
}

