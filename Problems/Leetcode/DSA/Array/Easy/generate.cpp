#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int getMaximumGenerated(int n)
  {
    if (n == 0) return 0;
    vector<int> arr(n + 1);
    arr[0] = 0, arr[1] = 1;
    int answer = 1;
    for (int i = 2; i <= n; ++i){
      arr[i] = arr[i / 2];
      if(i % 2) arr[i] += arr[i / 2 + 1];
      answer = max(answer, arr[i]);
    }
    return answer;
  }

};