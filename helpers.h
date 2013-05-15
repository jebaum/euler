#ifndef _HELPERS_H
#define _HELPERS_H

#include <inttypes.h>

// takes n as the upper limit of primes to be sieved
// returns an array of primes and puts the number of array entries in n
uint64_t* sievePrimes(uint64_t* n);

#endif
