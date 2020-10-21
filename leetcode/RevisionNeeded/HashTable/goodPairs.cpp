#include<bits/stdc++.h>
using namespace std;

class solution{
  public:
    int pairs(vector<int> &nums){
      map<int,int> map;
      int pair = 0;
      for (auto i : nums)
      {
        pair += map[i]++ ;
      }
      return pair;
    }
};

int main(){
  vector<int> vec = {1,2,3,1,1,3};
  solution good_pairs;
  cout<<good_pairs.pairs(vec)<<endl;
  return 0;
}