class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max_alt = 0, addUp = 0;
        
        for(auto g : gain){
            addUp += g;
            max_alt = max(max_alt, addUp);
        }
        
        return max_alt;
    }
};