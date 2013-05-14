/* If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
 *
 * If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
 *
 * NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
 */

#include <stdio.h>
#include <string.h>
int main()
{
  char i[37]="onetwothreefourfivesixseveneightnine";
  char j[71]="teneleventwelvethirteenfourteenfifteensixteenseventeeneighteennineteen";
  char k[47]="twentythirtyfortyfiftysixtyseventyeightyninety";
  char m[3]="and";
  char n[8]="hundred";
  char u[12]="onethousand";

  int letters = 190*strlen(i) + 10*strlen(j) + 100*strlen(k) + 9*99*strlen(m) + 900*strlen(n) + strlen(u);
  printf("answer is %d\n", letters);

}
