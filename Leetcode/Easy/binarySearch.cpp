#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int first = 0;
        int last = nums.size() - 1;
        int mid = (last + first) / 2;
        while(first <= last){
            if(nums[mid] > target) last = mid  - 1;
            else if(nums[mid] < target) first = mid + 1;
            else if (nums[mid] == target) return mid;
            mid = (first + last) /2;
        }
        return -1;
    }
};