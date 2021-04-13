class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
      map<int,int>m;  
      int count = 0;
      for(auto i: arr)  m[i]++;
      for(int i = 1; count < k; i++){
        if(m[i] == 0)  count++;
        if(count == k) return i;
      }
        return -1;
    }
};