#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  void reverse(string &str)
  {
    int len = str.length() ;
    for (int i = 0, j = len -1; i < j; ++i, --j)
      swap(str[i], str[j]);
  }
public:
  void translate(){
    string s,t;
    cin >> s >> t;
    reverse(s);
    s == t ? cout << "YES" : cout << "NO" ;
    cout << endl;
  }
};

int main()
{
  Solution translation;
  translation.translate();
  return 0;
}