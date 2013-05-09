/*
 *
 * A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 *
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */

#include <stdio.h>

int isPalindrome(int x)
{
  int original_number = x, digit=0, reverse=0;
  while (x>0)
  {
    digit   = x % 10;
    reverse = reverse * 10 + digit;
    x = x / 10;
  }
  return (original_number == reverse ? 1 : 0);
}

int main()
{
  int i,j,answer=0;

  for (i=999; i>=100; --i)
  {
    if (i*999 <= answer) // terminate if we can't find any bigger numbers
      break;

    for (j=999; j>=100; --j)
      if (isPalindrome(i*j) && i*j > answer)
      {
        answer = i*j;
        break;
      }
  }
  printf("largest palindrome is %d\n", answer);
}
