#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int>v;
  set<int>s;
  int n,m;
  cin >> n >> m;
  for(int i = 0; i < n; ++i ){
    int num;
    cin >> num;
    v.push_back(num);
  }
  while(m --){
    int l;
    cin >> l;
    for(int i = l - 1 ; i < n ; ++i) s.insert(v[i]);
    cout  << s.size() << endl;
    s.clear();
    }
  }