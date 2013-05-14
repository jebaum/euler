/* 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 *
 * What is the sum of the digits of the number 2^1000?
 */

#include <stdio.h>
#include <gmp.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  unsigned int i, sum=0;
  char* answer = malloc(1000);
  mpz_t n; // number with arbitrary precision
  mpz_init(n); // initialize the number
  mpz_set_ui(n,2); // set unsigned int. mpz_init_set_ui also exists

  for (i=2; i<=1000; ++i)
    mpz_mul_ui(n, n, 2);

  //mpz_out_str(stdout, 10, n);

  mpz_get_str(answer, 10, n); // convert n to base 10 and put it in a char*

  for (i=0; i<strlen(answer); ++i)
    sum+=answer[i] - '0';

  printf("sum of the %d digits is %d\n", strlen(answer), sum);

  mpz_clear(n);
  free(answer);
}
