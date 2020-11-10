#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
 bool isAnagram(string s, string t)
 {
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  return t == s;
 }

 bool isAnagram2(string s, string t)
 {
  int array[27] = {0};
  for(char i : s) array[i - 'a']++;
  for(char i : t) array[i - 'a']--;
  for(int i=0; i < 27; ++i){
   if(array[i]) return false;
  }
  return true;
 }
};