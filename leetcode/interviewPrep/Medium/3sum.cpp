
class Solution {
	
	map<int,int>number_lookup;

	vector<int>twoSum(vector<int>nums, int val, int starting_position){
		while(starting_position < nums.size()){
			if((val - number_lookup[nums[starting_position++]]) > 0)
				return {val - number_lookup[nums[starting_position++]], number_lookup[nums[starting_position++]]};
		}
		return {};	
	}

public:
	vector<vector<int>> threeSum(vector<int>& nums) {

		for(auto num : nums )
			number_lookup[num]++;

		if(number_lookup.size() == 1){
			if(number_lookup[0] >= 3)return{{0, 0, 0}};
			else return {};
		}

		set<vector<int>>set;
		vector<vector<int>> _3sum;

		for(int i = 0; i < nums.size(); ++i){
			vector<int>_2sum = twoSum(nums, 0 - nums[i], i + 1);
			if(_2sum.size() !=  0){
				_2sum.push_back(nums[i]);
				_3sum.push_back(_2sum);
			}
		}

		return _3sum;

	}
};