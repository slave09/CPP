#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
     unordered_map<int,int>mapka;
     for(int i = 0; i < nums.size(); ++i){
        if(mapka.count(nums[i]) == 0)
            mapka[nums[i]] = i;
        else if( (abs(mapka[nums[i]] - i)) <= k)
            return true;
        else
            mapka[nums[i]] = i;
     }
     return false;
    }

    bool otherSolution(vector<int> &nums, int k){
        unordered_set<int>sets;
        if(k >= nums.size()) k = nums.size() - 1;
        if(k <= 0) return false;
        for (int i = 0; i < nums.size(); i++)
        {
            if(i > k) sets.erase( nums[i - k - 1] );
            if(sets.find(nums[i]) != sets.end())
                return true;
            sets.insert(nums[i]);
        }
        return false;
    }
};

int main(){
    vector<int> v{1,2,3,1};
    Solution myanswere;
    if(myanswere.otherSolution(v,3)) cout<<"true";
    else cout<<"false!";
    return 0;
}