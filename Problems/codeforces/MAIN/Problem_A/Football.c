/*
  Problem 96A
*/

#include <stdio.h>
#include <string.h>
int main()
{
  char player[100];
  char p;
  int count, length;

  count = 1;
  gets(player);
  p = player[0];
  length = strlen(player);

  if (length < 7)
  {
    printf("NO");
    return 0;
  }

  for (int i = 1; i < length; i++)
  {
    if (p == player[i])
    {
      count++;
      if (count == 7)
      {
        printf("YES");
        return 0;
      }
    }
    else
    {
      count = 1;
      p = player[i];
    }
  }
  
  printf("NO");

  return 0;
}