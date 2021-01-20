/*
  Problem 266B
*/

#include <iostream>
using namespace std;

int main()
{
  int stud, time;
  char line[50], c;
  cin >> stud >> time >> line;

  while (time--)
  {
    for (int i = 0; i < stud; i++)
    {
      if (line[i] == 'B' && line[i + 1] == 'G')
      {
        c = line[i];
        line[i] = line[i+1];
        line[i+1] = c;
        i++;
      }
    }
  }

  cout<<line;

  return 0;
}