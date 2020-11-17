#include <bits/stdc++.h>
using namespace std;
int main(){
  unordered_map<int, int> m;
  int n, M, l1, r1, answer = 0;
  cin >> n >> l1 >> r1;
  for (int i = l1; i <= r1; ++i) m[i]++;
  for (int i = 0; i < n - 1; ++i){
    cin >> l1 >> r1;
    for (int i = l1; i <= r1; ++i){
      if (m.count(i)){
        m[i]++;
        if (m[i] == M) answer++;
      }
    }
  }
  cout << answer << " ";
  return 0;
}