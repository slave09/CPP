#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
  {
    unordered_map<int, int> map;
    vector<int>result;
    set<int> answere;
    for (auto i : nums1)
      map[i]++;
    for(int i = 0; i < nums2.size(); ++i){
      if(map.count(nums2[i]) != 0 )
        answere.insert(nums2[i]);
    }
    for(auto i : answere)
      result.push_back(i);
    return result;
  }
};