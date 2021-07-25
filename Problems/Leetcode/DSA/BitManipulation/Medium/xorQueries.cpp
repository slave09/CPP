class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) { 
        vector<int> res; // res will store the result of each queries
        for (int i = 1; i < arr.size(); ++i)
            arr[i] ^= arr[i - 1]; // modifying array elements with its last xor
        for (auto &q: queries)
            res.push_back(q[0] > 0 ? arr[q[0] - 1] ^ arr[q[1]] : arr[q[1]]);
        return res;
    }
};