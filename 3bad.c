/* The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number 600851475143?
 *
 * NOTE - this was pretty much my brain farting the shortest solution I could think of into existence
 * this is absolutely horrible since it iterates number/2 times no matter what, so impractical for very big numbers
 */
#include <stdio.h>

int main()
{
  long long int number = 13195;
  long long int factor = number;
  int i = 2, largest=2;

  while ( i <= number/2 )
  {
    if (factor%i == 0) // i is a factor
    {
      factor = factor / i;
      largest = i;
    }
    ++i;
  }
  if (largest == 2)
    printf("number is prime\n");
  else
    printf("largest prime factor is %d\n", largest);
}
