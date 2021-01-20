/*
  Problem 231A: The Team
*/

#include <stdio.h>

int main()
{
  int n, f, s, t;
  int count = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d%d%d",&f, &s, &t);
    if(f == 1 && s == 1)
    count++;
    else if(f == 1 && t == 1)
    count++;
    else if(s == 1 && t == 1 )
    count++;
    else if(f == 1 && s == 1 && t == 1)
    count++;
  }
  printf("%d",count);
  return 0;
}