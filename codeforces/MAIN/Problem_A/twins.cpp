/*
  Problem 160A
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int coins, *value, sum = 0, total = 0, i;

  cin >> coins;
  value = new int[coins];

  // Read coins and calculate its sum
  for (int i = 0; i < coins; i++)
  {
    cin >> value[i];
    sum += value[i];
  }

  //sort coins in descending order
  sort(value, value + coins, greater<int>());

  // check whether the sum of front most coins are strictly greater than half of it's sum
  for (i = 0; i < coins; i++)
  {
    if (total < (sum / 2) + 1)
    {
      total += value[i];
    }
    else
    {
      printf("%d", i);
      return 0;
    }
  }

  printf("%d", i);

  return 0;
}