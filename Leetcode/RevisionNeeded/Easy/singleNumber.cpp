#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int elem = nums[0];
        for(int i = 1; i < nums.size(); i++)
            elem = elem ^ nums[i];
        return elem;
    }
};