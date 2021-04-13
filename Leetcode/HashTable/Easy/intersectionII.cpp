#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> map;
    vector<int> answere;
    for (auto i : nums1)
      map[i]++;
    for(int i = 0; i < nums2.size(); ++i){
      if(map.count(nums2[i]) && map[nums2[i]] != 0){
        answere.push_back(nums2[i]);
        map[nums2[i]] --; 
      }
    }
    return answere;
    }
};