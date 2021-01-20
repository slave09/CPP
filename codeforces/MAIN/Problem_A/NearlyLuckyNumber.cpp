/*
  Problem: 110A
*/

#include <bits/stdc++.h>
using namespace std;

void check_lucky(long long number)
{
  int count = 0;
  while (number > 0)
  {
    if (number % 10 == 4 || number % 10 == 7)
      count++;
    number /= 10;
  }
  if (count == 0)
  {
    cout << "NO";
    return;
  }
  while (count)
  {
    if (count % 10 != 4 && count % 10 != 7)
    {
      cout << "NO";
      return;
    }
    else
      count /= 10;
  }
  cout << "YES";
}

int main()
{
  long long number;
  cin >> number;
  check_lucky(number);
  return 0;
}