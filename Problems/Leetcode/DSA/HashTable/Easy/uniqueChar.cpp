#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
      unordered_map<char,int>mapwa;
      for(auto i : s) mapwa[i]++;
      for(int i = 0; i < s.size(); ++i)
        if(mapwa[s[i]] == 1) return i;
      return -1;
    }

    int otherSolution(string s){
      unordered_map<char,pair<int,int>>umap;
      int index = s.size();
      for(int i = 0; i < s.size(); ++i)
        umap[s[i]].first++, umap[s[i]].second = i;
      for( auto &i : umap){
        if(i.second.first == 1) index = min(i.second.second,index);
      }
      return index == s.size() ? -1 : index;
    }
};