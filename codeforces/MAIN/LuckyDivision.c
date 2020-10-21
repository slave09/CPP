/*
  Problem 122A
*/

#include <stdio.h>

int checkLucky(int i)
{
  while (i > 0)
  {
    if (i % 10 != 4 && i % 10 != 7)
      return 0;
    i /= 10;
  }
  return 1;
}

int main()
{
  int number, c;
  scanf("%d", &number);

  if (checkLucky(number))
  {
    printf("YES");
    return 0;
  }

  for (int i = 1; i < number; i++)
  {
    if (checkLucky(i))
    {
      if (number % i == 0)
      {
        printf("YES");
        return 0;
      }
    }
  }
  printf("NO");
  return 0;
}