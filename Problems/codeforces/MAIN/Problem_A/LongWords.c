/*
  Problem 71A: Way too long words
*/

#include <stdio.h>
#include <string.h>
int main()
{
  int words, length;
  char input[100];
  scanf("%d", &words);
  for (int i = 0; i < words; ++i)
  {
    scanf("%s", &input);
    length = strlen(input);
    if (length > 10)
    {
      printf("%c%d%c\n", input[0], (length - 2), input[length - 1]);
      input[100] = 0;
    }
    else
    {
      printf("%s\n", input);
      input[100] = 0;
    }
  }
  return 0;
}