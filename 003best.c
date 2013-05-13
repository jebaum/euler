/* The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number 600851475143?
 */

#include <stdio.h>
int main()
{
  unsigned long long int number = 600851475143;
  int divisor = 2;
  while (number > 1)
  {
    if ( (number%divisor) == 0 )
    {
      number /= divisor;
      divisor--;
    }
    divisor++;
  }
  printf("answer is %d\n", divisor);
}

