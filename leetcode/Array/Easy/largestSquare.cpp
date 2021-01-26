class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int ans = INT_MIN;
        for(int i = 0; i < rectangles.size(); ++i){
            int possibleSide = min(rectangles[i][0], rectangles[i][1]);
            ans = max(ans, possibleSide);
        }
        return ans;
    }
};