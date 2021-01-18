class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, ans;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(mid == 0 ||nums[mid - 1] < nums[mid ]){
                ans = mid;
                low = mid + 1;  
            }
            
            else high = mid - 1;
        }
        return ans;
    }
};