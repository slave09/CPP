class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>>subset_array;
		int size = nums.size();
		int total_combinations = 1 << size;

		for(int i = 0; i < total_combinations; ++i){
			vector<int>curr_combination;
			for(int position = 0; position < size; ++position){
				if((i >> position) & 1){
					curr_combination.push_back(nums[position]);
				}
			}
			subset_array.push_back(curr_combination);
		}
		return subset_array;
	}
};