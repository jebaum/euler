/* Find the greatest product of five consecutive digits in the 1000-digit number.
 */

#include <stdio.h>
#include <string.h>

#define DIGITS 1000
#define SUBSEQUENCE_SIZE 5

int main()
{
  int i=0,j,product,largest=0;
  char numString[DIGITS+1];

  FILE* fin = fopen("files/008.txt", "r");
  while (fscanf(fin, "%s", &numString[i]) != EOF)
    i=strlen(numString);
  fclose(fin);

  printf("numString is %s\n", numString);

  for (i=0; i<=DIGITS-SUBSEQUENCE_SIZE; ++i)
  {
    product = 1;
    for (j=0; j<SUBSEQUENCE_SIZE; ++j)
    {
      product *= numString[i+j] - '0';
    }
    largest = (product > largest ? product : largest);
  }
  printf("largest product is %d\n", largest);
}
