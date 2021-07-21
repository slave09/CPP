class Solution {
    int binarySearch(vector<int> &numbers, int target, int index){
        int len = numbers.size() - 1;
        int first = index;
        int last = len;
        while(first <= last){
            int mid = (first + last) / 2;
            if(numbers[mid] == target) return mid + 1;
            if(numbers[mid] < target)
                first = mid + 1;
            else last = mid - 1;
        }
        return -1;
    }
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>res;
        for(int i = 0; i < numbers.size(); ++i){
            int idx = binarySearch(numbers,target - numbers[i], i+1);
            if(idx != -1){
                res.push_back(i + 1);
                res.push_back(idx );
                return res;
            }
        }
        return res;
    }
};