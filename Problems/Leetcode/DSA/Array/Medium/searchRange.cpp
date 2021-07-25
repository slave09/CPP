class Solution {
    int first_occurence(vector<int>arr, int target){
        int low = 0, high = arr.size() - 1;
        cout << arr.size() << " ";
        int first_position = arr.size();
        while(low <= high){
            int mid = (low + high ) / 2;
            if(arr[mid] >= target){
                first_position = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return first_position;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = first_occurence(nums, target);
        int last = first_occurence(nums, target + 1) - 1;
        if(first <= last) return {first, last};
        return {-1,-1};
    }
};