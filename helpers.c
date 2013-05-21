#include "helpers.h"
#include <math.h>
#include <stdlib.h>

uint64_t* sievePrimes(uint64_t* n)
{
  if (*n < 2) return NULL;

  char* primes = malloc (sizeof(char) * (*n+1)/2);
  const uint64_t loop_limit = (sqrt(*n) + 1) /2;
  uint64_t i,j;

  #pragma omp parallel for private(i)
  for (i=1; i<(*n+1)/2; ++i) // initialize sieve
    primes[i] = 'p';

  #pragma omp parallel for private(i,j) schedule(dynamic, 100)
  for (i=1; i <= loop_limit; ++i) // mark nonprimes with 'x'
    if (primes[i] == 'p')
      for (j=2*i*(i+1); j<(*n+1)/2; j+=(2*i+1))
        primes[j] = 'x';

  uint64_t* p = malloc (sizeof(uint64_t) * ((*n+1)/2));
  j=0;
  p[j++] = 2;

  for (i=1; i<(*n+1)/2; ++i)
    if (primes[i] == 'p')
      p[j++] = 2*i+1;

  free(primes);
  *n = j;
  return realloc(p, j*(sizeof(uint64_t)));
}

uint64_t sumOfDivisors(uint64_t n)
{
  unsigned int k,p;
  uint64_t prod = 1;

  for (k=2; k*k <= n; ++k)
  {
    p = 1;
    while (n%k == 0)
    {
      p = p*k + 1;
      n /= k;
    }
    prod *= p;
  }
  if (n>1)
    prod *= 1+n;
  return prod;
}
