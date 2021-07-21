/*
  problem 118A
*/

#include <stdio.h>

int checkVowel(char input)
{
  if (input == 'A' || input == 'a')
    return 1;
  else if (input == 'E' || input == 'e')
    return 1;
  else if (input == 'I' || input == 'i')
    return 1;
  else if (input == 'O' || input == 'o')
    return 1;
  else if (input == 'U' || input == 'u')
    return 1;
  else if (input == 'Y' || input == 'y')
    return 1;
  return 0;
}

int main()
{
  char string[100];

  scanf("%s", &string);
  for (int i = 0; string[i] != '\0'; i++)
  {
    if (string[i] == ' ')
      ;
    else
    {
      if ( !checkVowel(string[i]) )
      {
        if (string[i] < 97)
          printf(".%c", string[i] + 32);
        else
          printf(".%c", string[i]);
      }
    }
  }

  return 0;
}