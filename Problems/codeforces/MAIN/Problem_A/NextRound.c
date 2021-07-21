/*
  Problem 158A: Next Round
*/

#include <stdio.h>
int main()
{
  int n, k, count;
  int a[50];
  scanf("%d%d", &n, &k);

  count = 0;

  for (int i = 0; i < k; i++)
  {
    scanf("%d", &a[i]);
    if (a[i] != 0)
      count++;
  }

  for (int j = k; j < n; j++)
  {
    scanf("%d", &a[j]);
    if (a[j] == a[k - 1])
    {
      if (a[j] != 0)
        count++;
    }
    else
      break;
  }

  printf("%d", count);

  return 0;
}