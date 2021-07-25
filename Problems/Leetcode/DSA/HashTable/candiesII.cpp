#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
      set<int> set;
      for(auto i : candies) set.insert(i);
      return min(set.size(),candies.size()/2);
    }
};