#include<bits/stdc++.h>
using namespace std;


int MaxIIIMultiplication(vector<int>&nums){
  sort(nums.begin(),nums.end());
  int last = nums.size()-1;
  int end = nums[last]*nums[last-1]*nums[last-2];
  int start = nums[0]*nums[1]*nums[last];
  return max(end,start);
}

int main(){
  vector<int> array{1,2,4,0,-9,-4,9,8,6,-5,0,0,3,3,3,7};
  cout<<MaxIIIMultiplication(array)<<'\n';
  return 0;
}