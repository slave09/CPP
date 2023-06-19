/*

	* You are given an integer array nums and an integer target.

	* You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

  * For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".

	* Return the number of different expressions that you can build, which evaluates to target.

	* On simplifying, we have to partition array in two subsets where the difference between the dum of theses subset equals target.
	* Find no of subsets possible

	* Derivation : sum(subset1) - sum(subset2) = target __________(1)
	* 						 sum(subset1) + sum(subset2) = sum(array)_______(2)
	* On adding eq 1 and 2, we get => sum(subset1) = (target + sum(array)) / 2 ____________(3)

	* Therefore Now the problem reduces to count the number of subsets whose sum is given by eq (3)

*/

class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int target) {
		int arraySum = 0;
		for(auto num : nums) arraySum += num;
			if((target + arraySum) % 2) return 0;
		int subsetSum = (target + arraySum) / 2;
		return countSubsetSum(nums, subsetSum);
	}

	int countSubsetSum(vector<int>&nums, int sum){
		if(sum < 0) return 0;
		vector<vector<int>>dp(nums.size() + 1, vector<int>(sum + 1, 0));
		dp[0][0] = 1;
		for(int i = 1; i <= nums.size(); ++i){
			for(int j = 0; j <= sum; ++j){
				if(nums[i - 1] <= j) dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
				else dp[i][j] = dp[i - 1][j];
			}
		}
		return dp[nums.size()][sum];
	}
};