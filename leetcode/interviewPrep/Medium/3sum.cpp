#include<bits/stdc++.h>
using namespace std;

class Solution {

public:
	vector<vector<int>> threeSum(vector<int>& nums) {

		if(nums.size() < 3) return {};

		int size = nums.size();
		map<int,int>lookup;
		vector<vector<int>>threeSumTriplets;
		set<vector<int>>triplets;

		for(auto num : nums)
			lookup[num]++;

		if(lookup.size() == 1 && lookup[0] > 2) return {{0,0,0}};

		for(int index = 0; index < size; ++index){

			int val = nums[index];
			int toFind = -1 * val;

			for(int key = index + 1; key < size; ++key){

				int value = toFind - nums[key];

				if(lookup[value] > 0){
					if(val == nums[key] == value && lookup[value] >= 3){
						triplets.insert({value,value,value});
						break;
					}
					else if( ( value != val && value != nums[key]) || lookup[value] > 1){
						int maxim = max(max(val, value), nums[key]);
						int minima = min(min(val, value), nums[key]);
						triplets.insert({maxim, 0 - maxim - minima, minima});
						break;
					}
				}
			}
		}

		for(auto triples : triplets)
			threeSumTriplets.push_back(triples);

		return threeSumTriplets;
	}
};

int main(){

	Solution _3sum;
	vector<int> nums = {-2,0,0,2,2};
	vector<vector<int>> num = _3sum.threeSum(nums);
	for(int i = 0; i < num.size(); ++i){
		cout << "[" ;
		for(int j = 0; j < 3; ++j)
			cout << num[i][j] << ",";
		cout << "],";
	}
	return 0;
}