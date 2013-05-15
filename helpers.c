#include "helpers.h"
#include <math.h>
#include <stdlib.h>

uint64_t* sievePrimes(uint64_t* n)
{
  if (*n < 2) return NULL;

  char primes[(*n+1)/2];
  uint64_t i,j;

  for (i=1; i<(*n+1)/2; ++i) // initialize sieve
    primes[i] = 'p';

  for (i=1; i <= (sqrt(*n)+1)/2; ++i) // mark nonprimes with 'x'
    if (primes[i] == 'p')
      for (j=2*i*(i+1); j<(*n+1)/2; j+=(2*i+1))
        primes[j] = 'x';

  uint64_t* p = malloc (sizeof(uint64_t) * ((*n+1)/2));
  j=0;
  p[j++] = 2;

  for (i=1; i<(*n+1)/2; ++i)
    if (primes[i] == 'p')
      p[j++] = 2*i+1;

  *n = j;
  return realloc(p, j*(sizeof(uint64_t)));
}

