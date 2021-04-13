#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
		 vector<int> findErrorNums(vector<int>& nums) {
			 int size = nums.size();

			 int total = size * (size + 1) / 2;

			 int addUp = 0;

			 int repeated;

			 map<int,int>lookup;

			 for(auto num : nums){
				 lookup[num]++;
				 if(lookup[num] > 1) repeated = num;
				 addUp += num;
			 }

			 int missing = total - (addUp - repeated);

			 return {repeated, missing};
    }
};
