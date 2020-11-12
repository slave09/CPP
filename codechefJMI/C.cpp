#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> v(n + 1, 0);
  unordered_set<string> s;
  for (int i = 1; i <= x; i++)
  {
    int t1, t2;
    cin >> t1 >> t2;
    v[t1]++;
    v[t2]++;
    string tmp = "(" + to_string(t1) + " " + to_string(t2) + ")";
    s.insert(tmp);
  }

  for (int i = 1; i <= y; i++)
  {
    int t1, t2;
    cin >> t1 >> t2;
    string tmp = "(" + to_string(t1) + " " + to_string(t2) + ")";
    if (s.find(tmp) == s.end())
    {
      v[t1]++;
      v[t2]++;
    }
  }

  for (int i = 1; i <= n; i++)
    cout << v[i] << " ";
  cout << endl;
  return 0;
}