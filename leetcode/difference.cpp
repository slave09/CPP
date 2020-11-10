#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        for(int i = 0; i < s.size(); ++i){
          if( (s[i]-t[i]) !=  0) return t[i];
        }
        return t[t.size()-1];
    }
};