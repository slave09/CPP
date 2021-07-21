#include<bits/stdc++.h>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      vector<int>result;
      unordered_map<int,pair<int,int>>nums_count;
      for(int i = 0; i < nums.size(); ++i){
        nums_count[nums[i]].first++;
        nums_count[nums[i]].second = i;
      }
      for(int i = 0; i < nums.size(); ++i){
        int possible_number = target - nums[i];
        if(nums_count.count(possible_number)&& nums_count[possible_number].second != i){
          result.push_back(i);
          result.push_back(nums_count[possible_number].second);
          return result;
        }
      }
    return result;
  }

  vector<int> twoSumII(vector<int>& nums, int target) {
    unordered_map<int,int>indices;
    for(int i = 0; i < nums.size(); ++i)
      indices[nums[i]] = i;
    // for(int i = 0; i < indices.size(); ++i)
    //   cout<<indices[nums[i]]<<" ";
    for(int i = 0; i < nums.size(); ++i){
      if(indices.count(target - nums[i])){
        if(indices[target - nums[i]] == i) continue;
        else{
          vector<int>result;
          result.push_back(i);
          result.push_back(indices[target - nums[i]]);
          return result;
        }
      }
    }
    return nums;;
  }
};