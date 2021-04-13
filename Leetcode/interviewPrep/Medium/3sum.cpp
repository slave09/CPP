class Solution {

public:
	vector<vector<int>> threeSum(vector<int>& nums) {

		if(nums.size() < 3) return {};

		int size = nums.size();
		map<int,int>lookup;
		vector<vector<int>>threeSumTriplets;
		set<vector<int>>triplets;

		for(auto num : nums)
			lookup[num]++;

		if(lookup.size() == 1 && lookup[0] > 2) return {{0,0,0}};


		if(lookup.size() == 3){
			int sum = 0;
			for(auto map : lookup)
				sum += map.second;

			if(sum == 0)
				return {{}}
		}

		for(int index = 0; index < size; ++index){

			int val = nums[index];
			int toFind = -1 * val;

			for(int key = index + 1; key < size; ++key){

				int value = toFind - nums[key];

				if(lookup[value] > 0){

					if(val == nums[key] && val == value && lookup[value] >= 3){
						triplets.insert({value,value,value});
					}
					if(val == nums[key] && val == value && lookup[value] < 3)
						break;
					
					else if( ( value != val && value != nums[key]) || lookup[value] == 2){
						int maxim = max(max(val, value), nums[key]);
						int minima = min(min(val, value), nums[key]);
						triplets.insert({maxim, 0 - maxim - minima, minima});
					}
				}
			}
		}

		for(auto triples : triplets)
			threeSumTriplets.push_back(triples);

		return threeSumTriplets;
	}
};