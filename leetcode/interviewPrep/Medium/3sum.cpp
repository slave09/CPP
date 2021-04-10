
class Solution {

	int search(vector<int>nums, int val,int index){
		int low = 0, high = nums.size() - 1 ;
		while(low <= high){
			int mid = low + (high - low)/2;
			if(mid == index) low = mid - 1;
			else if(nums[mid] == val) 
				return mid;
			else if(nums[mid] > val) 
				high = mid - 1;
			else 
				low = mid + 1;
		}
		return -1;
	}

	vector<int> twoSum(vector<int>nums, int val, int index){
		for(int i = index; i < nums.size(); ++i){
			int key = search(nums, val - nums[i], i );
			if(key != -1){
				cout << nums[i] << nums[key] <<  " ";
				return {nums[i], val-nums[i]};
			}
		}
		return {};
	}

public:
	vector<vector<int>> threeSum(vector<int>& nums) {
    
    if(nums.size() == 0) return {};
    
		vector<vector<int>> three_sum;
		set<vector<int>> set;
		sort(nums.begin(), nums.end());

		if(nums.front() == 0 && nums.back() == 0 && nums.size() >= 3) return {{0,0,0}};
		if(nums.front() >= 0 || nums.back() < 0) return {};

		for(int i = 0; i < nums.size(); ++i){
			vector<int> complement_pairs = twoSum(nums, -1*nums[i], i + 1);
			if(complement_pairs.size() == 2){
				complement_pairs.push_back(nums[i]);
				sort(complement_pairs.begin(), complement_pairs.end());
				set.insert(complement_pairs);
			}
		}

		for(auto s : set)
			three_sum.push_back(s);
		return three_sum;
	}
};