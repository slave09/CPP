class Solution {
public:
    int arrangeCoins(int n) {
        
        int step = 1, ans = 0;
        
        while(n){
            if(n >= step) ans ++;
            else return ans;
            n -= step;
            step++;
        }
        return ans;
    }
};