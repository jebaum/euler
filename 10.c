/* The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *
 * Find the sum of all the primes below two million.
 */

#include <stdio.h>
#include <math.h>
#define UPPER_LIMIT 2000000

int main()
{
  char primes[UPPER_LIMIT];
  int i,j;
  double sum = 2;

  for (i=3; i<UPPER_LIMIT; ++i) // initialize sieve
    primes[i] = 'p';

  for (i=3; i <= sqrt(UPPER_LIMIT); i+=2) // mark nonprimes with 'x'
  {
    if (primes[i] == 'p')
    {
      for (j=i*i; j<UPPER_LIMIT; j+=i)
      {
        primes[j] = 'x';
      }
    }
  }

  for (i=3; i<UPPER_LIMIT; i+=2)
  {
    if (primes[i] == 'p')
      sum+=(double)i; // I couldn't get unsigned long long ints to work, and floats weren't precise enough
  }
  printf("sum is %f\n", sum);
}

