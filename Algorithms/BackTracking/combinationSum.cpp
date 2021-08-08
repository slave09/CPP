#include <bits/stdc++.h>
using namespace std;

class Solution{
  void BackTrack(vector<vector<int>>&res, vector<int> temp, vector<int> candidates, int value, int start);

public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target){
    vector<vector<int>>res;
    vector<int> v = {};
    sort(candidates.begin(), candidates.end());
    BackTrack(res, v, candidates, target, 0);
    return res;
  }
};

void Solution :: BackTrack(vector<vector<int>>&res, vector<int> temp, vector<int> candidates, int value, int start){
  
  if(value < 0) return;

  if(value == 0){
    res.push_back(temp);
  }

  for(int i = start; i < candidates.size(); ++i){
    temp.push_back(candidates[i]);
    BackTrack(res, temp, candidates,  value - candidates[i], i);
    temp.pop_back();
  }
}

int main(){
  Solution sol;
  vector<int>cand = {2,3,6,7};
  vector<vector<int>>res;
  res = sol.combinationSum(cand, 7);
  
  for(auto r : res){
    for(auto num : r){
      cout << num << " ";
    }
    cout << endl;
  }
  return 0;
}