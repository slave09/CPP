class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        if(k == 1) return 0;
        
        unordered_map<int,int>frequency_lookup;
        int operations = 0;
        
        for(auto num : nums) frequency_lookup[num]++;
        
        for(int v : nums){
            if( 2 * v == k) operations += frequency_lookup[v] / 2;
            else  operations += min(frequency_lookup[v] ,frequency_lookup[k - v] );
            frequency_lookup[v] = frequency_lookup[k - v] = 0;
        }
        
        return operations;
    }
};