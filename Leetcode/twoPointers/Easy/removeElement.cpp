class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int size = nums.size();
		int next = 0;
		for(auto key : nums){
			if(key != val)
				nums[next++] = key; 
		}
		return next ;
	}
};