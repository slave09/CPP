#include <bits/stdc++.h>
using namespace std;
class Solution {
  void BackTrack(vector<vector<int>>&res, vector<int>candidates, vector<int>currCombination, int target, int start);
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int>currCombination;

    sort(candidates.begin(), candidates.end());
    BackTrack(res,candidates,currCombination,target,0);

    return res;
  }
};

void Solution :: BackTrack(vector<vector<int>>&res, vector<int>candidates, vector<int>currCombination, int target, int start){
  if(target < 0) return;
  
  if(target == 0)
    res.push_back(currCombination);

  for(int i = start; i < candidates.size(); ++i){

    if(i > start && candidates[i] == candidates[i-1]) continue;
    
    currCombination.push_back(candidates[i]);
    BackTrack(res,candidates,currCombination,  target - candidates[i], i + 1);
    
    currCombination.pop_back();
  }
}

/*
[10,1,2,7,6,1,5]   1 1 2 
8

[1,1,2,5,6,7,10]
8
*/

int main(){
  Solution sol;
  vector<vector<int>> combinationSum;
  vector<int>values = {10,1,2,7,6,5,1};
  combinationSum = sol.combinationSum2(values, 8);

  for(auto sum : combinationSum){
    cout << "[" ;
    for(auto num : sum){
      cout << num << ",";
    }
    cout << "\b" ;
    cout << "]" ;
  }
  return 0;
}