/* Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.
 *
 * For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.
 *
 * What is the total of all the name scores in the file?
 */

// NOTE - piped the file to 'sort' on shell to sort it, 022.txt is sorted
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

int main()
{
  int i, j=1,namesum=0;
  uint64_t totalsum=0;
  char name[20], c; // 46k file

  FILE* fin = fopen("files/022.txt", "r");
  while ( (fscanf(fin, "%s", name)) != EOF)
  {
    namesum=0;
    for (i=0; i<strlen(name); ++i)
      namesum += name[i] - 'A' +1;
    totalsum += namesum * j++;
  }
  fclose(fin);

  printf("sum is %llu\n", totalsum);
}

