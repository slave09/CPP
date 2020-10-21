/*
Problem 69A
*/

#include <stdio.h>

int main()
{
  int n, force;
  int sum[3] = {0};
  scanf("%d", &n);

  for(int i = 0; i < n; i++ ){
    for (int j = 0; j < 3; j++)
    {
      scanf("%d", &force);
      sum[j] += force;
    }
  }
  if (sum[0] == 0 && sum[1] == 0 && sum[2] == 0)
    printf("YES");
  else
    printf("NO");

  return 0;
}