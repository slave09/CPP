class Solution {
    vector<int>original;
    vector<int>num;
public:
    Solution(vector<int>& nums) {
        original.resize(nums.size());
        num.resize(nums.size());
        original = nums;
        num = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int size = original.size();
        int ranIndex = ((rand() % 9) + 1) % size;
        int ranIndex2 = (rand() % 10) % size;
        swap(num[ranIndex], this -> num[ranIndex2]);
        return num;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */