#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
      map<int,int>m;
      int answere = 0;
      for(auto i: deck) m[i]++;
      for(auto i : m) answere = __gcd(i.second, answere);
      return answere > 1;
    }
};