/* A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
 * a^2 + b^2 = c^2
 *
 * For example, 32 + 42 = 9 + 16 = 25 = 52.
 *
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 */

// a+b>c, so c<=499
// b > a

#include <stdio.h>

int main()
{
  int a, b, c;

  for (a=1; a<=1000; ++a)
  {
    for (b=a+1; b<=1000-a; ++b)
    {
      c = 1000 - a - b;
      if ( a<b && (a*a + b*b == c*c) )
      {
        printf("a * b * c = %d * %d * %d = %d\n", a, b, c, a*b*c);
        break;
      }
    }
    if (b < 1001-a) // if we found the answer and left inner loop early, b won't have finished incrementing
      break;
  }
  return 1;
}
