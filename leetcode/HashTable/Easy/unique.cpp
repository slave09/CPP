class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
      map<int,int>map;
      set<int>set;
      for(auto i : arr) map[i] ++;
      for(auto &j : map )
        if(!set.insert(j.second).second) return false;
      return true;
    }
};