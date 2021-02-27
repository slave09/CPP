#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
	 bool isSubsequence(string s, string t) {
		
		 int subIndex = 0;
		 int stringIndex = 0;

		 while(stringIndex < t.size()){
			 if(s[subIndex] == t[stringIndex])
				 subIndex++;
			 stringIndex++;
		 }
		
		 return subIndex >= s.size() ? true : false;

        }
};

