#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int test ;
  cin>>test;
  while(test--){
    int length;
    vector <int> s1, s2;
    cin>> length;
    for (int i = 0; i < length; i++)
    {
      int value;
      cin>>value;
      if(i <= length/2) s1.push_back(value);
      else s2.push_back(value);
    }
    s1.sort(s1.begin(),s1.end());
    s2.sort(s2.begin(),s2.end());
    

  return 0;
}