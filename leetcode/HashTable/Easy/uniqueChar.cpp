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
};