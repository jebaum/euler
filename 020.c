/*n! means n × (n − 1) × ... × 3 × 2 × 1
 *
 * For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
 * and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
 *
 * Find the sum of the digits in the number 100!
 */

#include <stdio.h>
#include <gmp.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  unsigned int i,sum=0;
  char* answer = malloc(200);

  mpz_t n;
  mpz_init(n);
  mpz_set_ui(n,100);

  for (i=99; i>1; --i)
    mpz_mul_ui(n, n, i);

  mpz_get_str(answer, 10, n);
  for (i=0; i<strlen(answer); ++i)
    sum+=answer[i] - '0';

  printf("sum of the %d digits is %d\n", strlen(answer), sum);

  mpz_clear(n);
  free(answer);
}
