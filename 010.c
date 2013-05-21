/* The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *
 * Find the sum of all the primes below two million.
 */

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include "helpers.h"

#define UPPER_LIMIT 2000000

int main()
{
  uint64_t i, sum=0;
  uint64_t bound = UPPER_LIMIT;
  uint64_t* primes = sievePrimes(&bound);

  #pragma omp parallel for reduction (+:sum) private(i)
  for (i=0; i< bound; ++i) // sum them up
    sum+=primes[i];

  printf("sum is %llu\n", sum);
}

