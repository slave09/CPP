class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int product = 1;
    int zero = 0;

    for(auto num : nums){
      if(num != 0) product *= num;
      else zero++;
    }

    if(zero > 1){
      for(int i = 0; i < nums.size(); ++i){
        nums[i] = 0;
      }
      return nums;
    }

    for(int i = 0; i < nums.size(); ++i){
      if(zero == 1 && nums[i] != 0) nums[i] = 0;
      else if(nums[i] == 0) nums[i] = product;
      else nums[i] = product / nums[i];
    }

    return nums;
  }
};

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {


    int size = nums.size();
    vector<int>res(size);
    res[0] = 1; // leftward product of zero's index

    for(int i = 1; i < size; ++i)
      res[i] = res[i-1]*nums[i-1];

    int leftValue = 1;

    for(int j = size - 1; j >= 0; ++j){
      res[j] *= leftValue;
      leftValue *= nums[j];
    }
    return res;
  }
};

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {

    int size = nums.size();
    vector<int>res(size);
    res[0] = 1; // leftward product of zeroth index

    for(int i = 1; i < size; ++i)
      res[i] = res[i-1] * nums[i-1];

    int leftValue = 1;

    for(int j = size - 1; j >= 0; --j){
      res[j] *= leftValue;
      leftValue *= nums[j];
    }
    return res;
  }
};