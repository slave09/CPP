class Solution {
public:
	vector<int> shuffle(vector<int>& nums, int n) {
		vector<int>result;
		for(int i = 0, j = n; i < n; i++, j++){
			result.push_back(nums[i]);
			if(j < nums.size()) result.push_back(nums[j]);
		}
		return result;
	}
};


/*
EXPLANATION:

Prerequisites:
Some bit manipulation knowledge will be helpful in understanding this algorithm. This algorithm uses:

Bitwise AND &
Bitwise OR |
Left Shift <<
Right Shift >>
Binary Representations of Numbers
Intuition:

-> This in-place algorithm relies on the constraint 1 <= nums[i] <= 10^3. 
-> This means the largest possible number in the nums array is 1000.
-> The binary representation of 1000 is 1111101000.
-> If we count the number of bits in 1111101000 we get 10.
-> Because the largest possible number only uses 10 bits, we can fit two numbers into one 32-bit binary representation.
-> This means we can store pairs of numbers in one binary representation without fear of overwriting a number.
*/

class Solution {
public:
	vector<int> shuffle(vector<int>& nums, int n) {
		for(int i = n - 1, j = nums.size()-1; j >= n; j--,--i){
			nums[j] = nums[j] << 10;
			nums[j] |= nums[i];
		}
		for(int j = n, i = 0; j < nums.size(); ++j, i += 2){
			nums[i] = nums[j] & (0b1111111111);
			nums[i+1] = nums[j] >> 10;
		}
		return nums;
	}
};