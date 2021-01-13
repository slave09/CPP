#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s == " ") return 0;
        int last_length = 0;
        for(auto i = s.rbegin(); i < s.rend(); ++i){
            if( *i == ' ' && last_length != 0) break;
            else if(*i == ' ') continue;
            else last_length++;
        }
        return last_length;
    }
};