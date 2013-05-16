/* In the 20x20 grid below, four numbers along a diagonal line have been marked in red.
 * The product of these numbers is 26 * 63 * 78 * 14 = 1788696.
 *
 * What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 20×20 grid?
 */

#include <stdio.h>
#define GRID_X 20
#define GRID_Y 20
#define SUBSEQUENCE_SIZE 4

unsigned int product=1, largest=0;

void store()
{
  extern unsigned int largest,product;
  largest = (product > largest ? product : largest);
  product = 1;
}

int main()
{
  int grid[GRID_X][GRID_Y];
  int x,y,i=0,j=0;
  extern unsigned int product,largest;

  FILE* fin = fopen("files/011.txt", "r");
  while ( (fscanf(fin, "%d", &grid[i][j++])) != EOF)
  {
    if (j == GRID_Y)
    {
      j = 0;
      ++i;
    }
  }
  fclose(fin);

  for (x=0; x<GRID_X; ++x)
  {
    for (y=0; y<GRID_Y; ++y)
    {
      if (x<=(GRID_X - SUBSEQUENCE_SIZE)) // check vertical adjacents
      {
        for (i=x; i<x+SUBSEQUENCE_SIZE; ++i)
          product *= grid[i][y];
      }
      store();

      if (y<=(GRID_Y - SUBSEQUENCE_SIZE)) // check horizontal adjacents
      {
        for (i=y; i<y+SUBSEQUENCE_SIZE; ++i)
          product *= grid[x][i];
      }
      store();

      if (x<=(GRID_X - SUBSEQUENCE_SIZE) && y<=(GRID_Y - SUBSEQUENCE_SIZE)) // check diagonals right
      {
        for (i=x,j=y; i<x+SUBSEQUENCE_SIZE && j<y+SUBSEQUENCE_SIZE; ++i,++j)
          product *= grid[i][j];
      }
      store();

      if (x>=3 && y<=(GRID_Y - SUBSEQUENCE_SIZE)) // check diagonals left
      {
        for (i=x,j=y; i>=0,j<y+SUBSEQUENCE_SIZE; --i,++j)
          product *= grid[i][j];
      }
      store();
    }
  }
  printf("largest product is %u\n", largest);
}
