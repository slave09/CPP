#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0, left_itr = 0, right_itr = height.size() - 1;
        while(left_itr < right_itr){
            int area = min(height[left_itr], height[right_itr])*(right_itr - left_itr);
            max_area = max(max_area, area);
            if(height[left_itr] < height[right_itr] ) 
                left_itr++;
            else right_itr--;
        }
        return max_area;
    }
};