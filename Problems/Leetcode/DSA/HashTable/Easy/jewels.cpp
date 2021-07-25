#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
      map <char,int>map;
      int count = 0;
      for(auto i : S)
        map[i] ++;
      for(int i = 0; i < J.length(); i++)
        count += map[J[i]];
      return count;
    }
};