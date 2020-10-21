/*
  Problem 58A
*/

#include <stdio.h>

int main()
{
  char s[6] = "hello";
  int c,i=0;

  while((c=getchar()) != EOF){
    if(s[i] == c)
    i++;
  }

  i == 5 ? printf("YES") : printf("NO");
  return 0;
}