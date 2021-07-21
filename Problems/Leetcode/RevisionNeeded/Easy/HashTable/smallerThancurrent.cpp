#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums){
      map<int,int>map;
      vector<int> copy = nums;
      sort(copy.begin(), copy.end());
      for(int i = 0; i < copy.size(); ++i)
        map.find(copy[i]) != map.end() ? : map[copy[i]] = i;
      for(int i = 0; i < nums.size(); ++i)
        nums[i] = map[nums[i]];
      return nums;
    }
};