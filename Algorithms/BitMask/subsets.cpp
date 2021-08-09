class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		int size = nums.size();
		int total_combinations = 1 << size;

		vector<vector<int>>subset_array(total_combinations);

		for(int i = 0; i < total_combinations; ++i){

			for(int position = 0; position < size; ++position){
				
				if((i >> position) & 1)
					subset_array[i].push_back(nums[position]);
			}
		}
		return subset_array;
	}
};