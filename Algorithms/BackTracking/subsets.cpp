class Solution {
  void BackTrack(vector<vector<int>>&res, vector<int>curr, vector<int>nums, int start);
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>>res;
    vector<int>curr;
    BackTrack(res, curr, nums, 0);
    return res;
  }
};

void Solution :: BackTrack(vector<vector<int>>&res, vector<int>curr, vector<int>nums, int start){
  res.push_back(curr);
  for(int i = start; i < nums.size(); ++i){
    curr.push_back(nums[i]);
    BackTrack(res, curr, nums, i + 1);
    curr.pop_back();
  }
}