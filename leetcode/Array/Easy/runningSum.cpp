#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
      int last = 0;
      for(int i = 0; i < nums.size(); ++i){
        nums[i] = nums[i] + last;
        last = nums[i];
      }
      return nums;
    }
};