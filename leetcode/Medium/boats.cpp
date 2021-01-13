#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0;
        sort(people.begin(), people.end());
        for(int i = 0, j = people.size() - 1; i <= j; ++i, --j){
            if(people[i] + people[j] <= limit) ans ++;
            else if(people[j] <= limit) ans++,i--;
        }
        return ans;
    }
};