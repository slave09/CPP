/*
Problem 282A
*/

#include <stdio.h>

int main()
{
  char statement[10];
  int n;
  int value = 0;

  scanf("%d", &n);

  while(n--)
  {
    scanf("%s", statement);
    if (statement[1] == '+')
      value++;
    else if (statement[1] == '-')
      value--;
  }
  printf("%d", value);
  return 0;
}