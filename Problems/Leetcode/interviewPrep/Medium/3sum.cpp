class Solution {

public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		set<vector<int>>triplets;
		vector<vector<int>> threeSumArr;
		for(int i = 0; i < nums.size(); ++i){
			for(int j = i + 1; j < nums.size(); ++j){
				for(int k = j + 1; k < nums.size(); ++k){
					int val = nums[i] + nums[j] + nums[k];
					if(val == 0)
					{
						int minima = min(min(nums[i], nums[j]), nums[k]);
						int maxima = max(max(nums[i], nums[j]), nums[k]);
						triplets.insert({minima, 0 - minima - maxima, maxima});
					}				
				}
			}
		}
		for(auto triples : triplets)
			threeSumArr.push_back(triples);
		return threeSumArr	;
	}
};