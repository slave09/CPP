class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int first = 0;
        int last = nums.size() - 1;
        int mid = (first + last) / 2;
        while(first <= last){
            if(nums[mid] > target){
                last = mid - 1;
                mid = (first + last) / 2;
            }
            else if(nums[mid] < target){
                first = mid + 1;
                mid = (first + last)/2;
            }
            else if(nums[mid] == target) return mid;
            else return last + 1;
        }
        return last + 1;
    }
};