class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
      int max = 0;
      vector<bool>res;
      for(int i = 0; i < candies.size(); ++i){
        max = candies[i] > max ? candies[i] : max;
        candies[i] += extraCandies;
      }
      for(int i = 0; i < candies.size(); ++i)
        candies[i] >= max ? res.push_back(true) : res.push_back(false);
      return res;
    }
};