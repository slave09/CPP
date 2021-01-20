/*
  Problem 339A
*/

#include <stdio.h>

int main()
{
  int s[3] = {0};
  int c, first = 0;
  while ((c = getchar()) != EOF)
  {
    if (c == '1')
      s[0]++;
    if (c == '2')
      s[1]++;
    if (c == '3')
      s[2]++;
  }
  for (int i = 0; i < 3; i++)
  {
    while (s[i] != 0)
    {
      if( first > 0) printf("+");
      first = 1;
      printf("%d", i + 1);
      s[i]--;
    }
  }
  return 0;
}