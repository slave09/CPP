class Solution {
 void BackTrack(vector<vector<int>>&res, vector<int>curr, vector<int>nums, vector<bool>available);
public:
 vector<vector<int>> permuteUnique(vector<int>& nums) {
  vector<vector<int>>res;
  vector<int>curr;
  vector<bool>available(nums.size());
  sort(nums.begin(), nums.end());
  BackTrack(res, curr, nums, available);
  return res;
 }
};

void Solution :: BackTrack(vector<vector<int>>&res, vector<int>curr, vector<int>nums, vector<bool>available){
 if(curr.size() == nums.size()) res.push_back(curr);
 else{
  for(int i = 0; i < nums.size(); ++i){
   if(available[i] || i > 0 && nums[i] == nums[i - 1] & !available[i - 1]) continue;
   available[i] = true;
   curr.push_back(nums[i]);
   BackTrack(res, curr, nums, available);
   available[i] = false;
   curr.pop_back();
  }
 }
}