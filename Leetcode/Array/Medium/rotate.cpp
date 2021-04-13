class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		k %= nums.size();
		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), nums.begin() + k );
		reverse(nums.begin() + k , nums.end());
	}
};


class Solution{
public:
	void rotate(vector<int> &nums, int k){

		k = k % nums.size();
		int count  = 0;
		
		for(int position = 0; count < nums.size(); ++position){
			int curr = position;
			int curr_val = nums[curr];
			do{
				int next_position = (curr + k) % nums.size();	
				int next_position_val = nums[next_position]; 			
				nums[next_position] = curr_val;
				curr_val = next_position_val;
				curr = next_position;
				count ++;
			}while(curr != position);
		}
	}
};