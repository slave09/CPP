class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
     set<int>s;
     for(int i : nums){
       s.insert(i);
     }
    return s.size() != nums.size();
    }
};

class Solution2 {
public:
    bool containsDuplicate(vector<int>& nums) {
     map<int,int>map;
     for(auto i : nums){
       map[i] ++;
       if(map[i]>1) return true;
     }
    return false;
    }
};