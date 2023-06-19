/*
	* partitioning a set of positive numbers into two subsets such that the sum of the numbers in each subset is equal
	* NP Hard Problem

	* If the sum is not even then we cannot partition array i two subsets of equal sum as total sum of array is not completely divisible by 2.
	* the problem is then reduced to find the subset of array whose sum = totalArraySum / 2
*/

class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int sum = 0;
		for(auto num : nums) sum += num;
			if(sum % 2) return false;
		return subsetSum(nums, sum / 2);
	}

	bool subsetSum(vector<int>&nums, int sum){
		vector<vector<bool>>dp(nums.size() + 1, vector<bool>(sum + 1, false));
		for(int index = 0; index < nums.size() + 1; ++index) dp[index][0] = true;
			for(int size = 1; size <= nums.size(); ++size){
				for(int curr = 1; curr <= sum; ++curr){
					if(nums[size - 1] <= curr){
						dp[size][curr] = dp[size - 1][curr] || dp[size - 1][curr - nums[size - 1]];
					}
					else dp[size][curr] = dp[size - 1][curr];
				}
			}
			return dp[nums.size()][sum];
		}
	};
