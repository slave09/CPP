#include<bits/stdc++.h>
using namespace std;
class Solution {
  void BackTrack(vector<vector<int>>&res, vector<int>curr, int n, int k, int value);
public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>>res;
    vector<int>curr;

    BackTrack(res, curr, n, k, 1);

    return res;
  }
};

void Solution :: BackTrack(vector<vector<int>>&res, vector<int>curr, int n, int k, int value){
  if(curr.size() == k) res.push_back(curr);

  for(int i = value; i <= n; ++i){
    curr.push_back(i);
    BackTrack(res, curr, n, k, i + 1);      
    curr.pop_back();
    
  }
}

int main(){
  Solution sol;
  vector<vector<int>>res = sol.combine( 4,2);
  for(auto r : res){
    for(auto num : r) cout << num << " ";
      cout << endl;
  }
  return 0;
}