/*
	If we had some way of counting instances of the majority element as +1+1 and instances of any other element as -1−1, 
	summing them would make it obvious that the majority element is indeed the majority element.
*/

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int count = 0;
		int candidate = 0;
		for(int arr : nums){
			if(count == 0) candidate = arr;
			count += candidate == arr ? 1 : -1;
		}
		return candidate;
	}
};