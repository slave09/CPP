#include <bits/stdc++.h>
using namespace std;

int main()
{
  map<string, int> strFreq;
  int test;
  cin >> test;
  while (test--)
  {
    string str;
    cin >> str;
    if (strFreq.count(str))
    {
      int n = strFreq[str];
      cout << str + to_string(n) << endl;
      strFreq[str]++;
    }
    else
    {
      cout << "OK" << endl;
      strFreq[str]++;
    }
  }

  return 0;
}