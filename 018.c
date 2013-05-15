/* By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.
 *
 *    3
 *   7 4
 *  2 4 6
 * 8 5 9 3
 *
 * That is, 3 + 7 + 4 + 9 = 23.
 *
 * Find the maximum total from top to bottom of the triangle below:
 * NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route. However, Problem 67, is the same challenge with a triangle containing one-hundred rows; it cannot be solved by brute force, and requires a clever method! ;o)
 */

#include <stdio.h>
#define SIZE 15
#define max(A,B) ((A)>(B)?(A):(B))

int main()
{
  int i,j,k=0;
  int raw[ (SIZE * (SIZE+1)) / 2];
  int triangle[SIZE][SIZE];

  for (i=0; i<SIZE; ++i) // initialize triangle
    for (j=0; j<SIZE; ++j)
      triangle[i][j] = -1;

  FILE* fin = fopen("files/018.txt", "r"); // read in data
  for (i=0; i<(SIZE * (SIZE+1)) / 2; ++i)
    fscanf(fin,"%d", &raw[i]);

  for (i=0; i<SIZE; ++i) // put data into triangle array
    for (j=0; j<=i; ++j)
      triangle[i][j] = raw[k++];

  for (i=SIZE-2; i>=0; --i)
    for (j=0; j<SIZE && triangle[i][j] != -1; ++j)
      triangle[i][j] += max(triangle[i+1][j], triangle[i+1][j+1]);

  printf("max sum is %d\n", triangle[0][0]);
}
