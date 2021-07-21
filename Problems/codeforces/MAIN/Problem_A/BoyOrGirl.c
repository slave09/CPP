/*
  Problem 236A
*/

#include <stdio.h>

int main()
{
  int arry[26] = {0};
  int c, count = 0;

  while ((c = getchar()) != EOF)
    arry[c - 'a']++;

  for (int i = 0; i < 26; i++)
  {
    if (arry[i] != 0)
      count++;
  }

  if (count % 2 == 0)
    printf("CHAT WITH HER!");
  else
    printf("IGNORE HIM!");

  return 0;
}