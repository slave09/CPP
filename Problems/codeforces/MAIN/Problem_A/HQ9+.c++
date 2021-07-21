/*
  Problem 133A
*/

#include <iostream>
using namespace std;

int main()
{
  char str[101];
  cin >> str;
  for (int i = 0; str[i] != '\0'; i++)
  {
    if (str[i] == 'Q' || str[i] == 'H' || str[i] == '9')
    {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}