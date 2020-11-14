#include <bits/stdc++.h>
using namespace std;

void test_case()
{
  int n, ai;
  cin >> n;
  int first = 0, second = 0;
  unordered_set<int> s;
  vector<int> v;
  for (int i = 0; i < n; ++i){
    cin >> ai;
    ai = pow(2, ai);
    v.push_back(ai);
  }
  sort(v.begin(), v.end());
  for (int k = 0; k < n; ++k){
    for (int i = k, j = n - 1; i < j; i++, j--)
    {
      first += v[i];
      second += v[j];
      if (s.find(first) != s.end() || s.find(second) != s.end()){
        cout << "YES" << '\n';
        return;
      }
      s.insert(first);
      s.insert(second);
    }
  }
  cout << "NO" << endl;
}

int main()
{
  int test;
  cin >> test;
  while (test--)
  {
    test_case();
  }
  return 0;
}