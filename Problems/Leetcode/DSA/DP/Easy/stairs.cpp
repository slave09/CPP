#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        long long arr[2] = {1,1};
        
        while(n--){
            long long temp = arr[0];
            arr[0] = arr[1];
            arr[1] = temp + arr[0];
        }
        return (int)arr[0];
    }
};