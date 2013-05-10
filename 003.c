/* The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number 600851475143?
 */

#include <stdio.h>
#include <stdlib.h>
#define BLOCKSIZE 512
typedef long long int* primeList;
int entries=0;

primeList generatePrimes(primeList p) // sticks prime numbers into p in BLOCKSIZE chunks, starting with 2
{
  extern int entries;
  int i,candidate,blocks;

  blocks = entries / BLOCKSIZE;

  if (entries == 0) // list is empty, initialize with 2 and 3
  {
    p = malloc(sizeof(long long int) * BLOCKSIZE);
    p[0] = 2;
    ++entries;
    p[1] = 3;
    ++entries;
  }
  else
    p = realloc(p, (1 + blocks) * sizeof(long long int) * BLOCKSIZE);

  ++blocks;
  while (entries < (blocks * BLOCKSIZE))
  {
    candidate = p[entries-1] + 2;

    for (i=0; i<(entries-1); ++i)
    {
      if (candidate % p[i] == 0) // if next candidate is divisble by an existing prime, increment and try again
      {
        candidate+=2;
        i = -1;
        continue;
      }
    }
    p[entries++] = candidate;
  }
  return p;
}

int main()
{
  extern int entries;
  int i=0, largest=-1;

  long long int number = 600851475143;
  primeList p = generatePrimes(p);

  while (i<entries && p[i] <= number/2) // loop through list of prime numbers
  {
    if (number % p[i] == 0) // if prime evenly divides our number
    {
      number = number / p[i];
      continue;
    }
    else
      ++i;

    if (i==entries && p[entries-1] > number/2)
    {
      break;
    }
    else if (i==entries && p[entries-1] < number/2)
    {
      p = generatePrimes(p);
      ++i;
      continue;
    }

  }
  printf("largest factor is %d\n", number);

}
