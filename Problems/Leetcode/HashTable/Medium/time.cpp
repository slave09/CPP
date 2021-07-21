class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int,int>remainder;
        int res = 0;
        for(int t : time){
            if(t % 60 == 0) res += remainder[0];
            else res += remainder[60 - t % 60];
            remainder[t % 60]++;
        }
        return res;
    }
};