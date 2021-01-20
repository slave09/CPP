/*
  Problem 263A
*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
  int a;
  for (int i = 1; i <= 5; i++)
  {
    for (int j = 1; j <= 5; j++)
    {
      scanf("%d", &a);
      if (a == 1)
      {
        printf("%d", abs(3 - i) + abs(3 - j));
        return 0;
      }
    }
  }
  return 0;
}