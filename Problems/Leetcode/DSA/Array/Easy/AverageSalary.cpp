#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    double average(vector<int>& salary) {
      double sum = 0.0;
      sort(salary.begin(),salary.end()); 
      for(int i = 1; i < salary.size()-1; i++){
        sum = sum + salary[i];
      }
      return sum/(salary.size() - 2);
    }
};