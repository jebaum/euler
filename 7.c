/* By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
 *
 * What is the 10 001st prime number?
 */

// using sieve of eratosthenes, implemented after reading wikipedia article on it

#include <stdio.h>
#include <math.h> // for square root
#define UPPER_LIMIT 105000 // changed this after getting correct answer to avoid unnecessary sieving
int main()
{
  char candidates[UPPER_LIMIT];
  int i,j,x=0;

  for (i=2; i<UPPER_LIMIT; ++i) // initialize sieve
    candidates[i] = 'p';

  for (i=3; i <= sqrt(UPPER_LIMIT); i+=2) // mark nonprimes with 'x'
  {
    if (candidates[i] == 'p')
    {
      for (j=i*i; j< UPPER_LIMIT; j+=i)
      {
        candidates[j] = 'x';
      }
    }
  }

  for (i=3; i<UPPER_LIMIT; i+=2) // find the 10,001st occurence of 'p'
  {
    if (candidates[i] == 'p')
      ++x;
    if (x == 10000) // 2 isn't being counted
      break;
  }
  printf("10,001st prime is %d\n", i);
}
