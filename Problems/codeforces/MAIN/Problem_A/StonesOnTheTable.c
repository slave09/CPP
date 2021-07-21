/*
  Problem 261A
*/

#include <stdio.h>

int main()
{
  int number, count;
  char ball[51];

  scanf("%d", &number);
  scanf("%s", ball);
  count = 0;

  for (int i = 0, j = 1; i < number, j < number; i++, j++)
  {
    if (ball[i] == ball[j])
      count++;
  }
  printf("%d", count);
  return 0;
}