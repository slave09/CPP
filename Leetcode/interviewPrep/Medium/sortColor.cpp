class Solution {
public:
  void sortColors(vector<int>& nums) {
    auto end = nums.end();
    for(auto i = nums.begin(); i < end; i++){
      if(*i == 0){
        nums.erase(i);
        nums.insert(nums.begin(), 0);
      }
      else if(*i == 2){
        nums.erase(i);
        nums.push_back(2);
        i--;
        end--;
      }
    }
  }
};


class Solution {
public:
  void sortColors(vector<int>& nums) {

   int i = 0, j = nums.size()-1;
   for(int k=0; k<=j; )
   {
    if(nums[k]==0)  swap(nums[i++], nums[k++]);
    else if(nums[k]==2)  swap(nums[j--], nums[k]);
    else k++;
  }        
}
};