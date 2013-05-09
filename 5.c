/* 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 *
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 */

#include <stdio.h>

int main()
{
  int i, number=1900, answer=0;
  int divisors[10] = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
  while (!answer)
  {
    for (i=0; i<10; ++i)
    {
      if (number % divisors[i]) // if not divisible by any number from 1 to 20
        answer = -1;
    }
    answer = (answer == -1 ? 0 : number);
    number+=19;
  }

  printf("smallest number is %d\n", answer);
}
