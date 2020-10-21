#include <stdio.h>

int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    int  n;
    scanf("%d",&n);
    char s[2*n+1];
    scanf("%s",&s);
    for (int i = 0; i < ((2 * n) - 1); i += 2)
      printf("%c",s[i]);
    printf("\n");
  }
  return 0;
}