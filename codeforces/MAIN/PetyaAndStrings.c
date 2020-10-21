/*
  Problem: 112A
*/

#include <stdio.h>
#include <ctype.h>
int main()
{
  char str1[100], str2[100];
  scanf("%s%s", str1, str2);
  for (int i = 0; str1[i] != '\0'; i++)
  {
    if (tolower(str1[i]) > tolower(str2[i]))
    {
      printf("%d", 1);
      return 0;
    }
    else if (tolower(str1[i]) < tolower(str2[i]))
    {
      printf("%d", -1);
      return 0;
    }
  }
  printf("%d",0);
  return 0;
}