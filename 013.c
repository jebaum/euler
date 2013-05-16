/* Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
*/

#include <stdio.h>

int main()
{
  char nums[100 + 1][50], sum[52];
  int i=0,j,k=0,carry=0;

  FILE* fin = fopen("files/013.txt", "r");
  while ( (fscanf(fin, "%s", &nums[i++][0]) != EOF) )
    continue;
  fclose(fin);

  for (j=49; j>=0; --j)
  {
    for (i=0; i<100; ++i)
    {
      carry += nums[i][j] - '0';
    }
    sum[k++] = carry % 10 + '0';
    carry /= 10;
  }

  while (carry)
  {
    sum[k++] = carry % 10 + '0';
    carry /= 10;
  }

  for (i=k-1; i>=0; --i)
    printf("%c", sum[i]);
  printf("\n");
}
