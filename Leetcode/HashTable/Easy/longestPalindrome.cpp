#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
      unordered_map<char,int>char_freq;
      int palindromeLength = 0;
      bool single_character = false;
      for(auto i : s) char_freq[i]++;
      for(int i = 0; i < char_freq.size(); ++i){
        if(char_freq[i] % 2 ){ 
          palindromeLength += char_freq[i]-1;
          single_character = true; 
        }
        else  palindromeLength += char_freq[i];
      }
      return single_character ? palindromeLength + 1 : palindromeLength;
    }
};