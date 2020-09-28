/*
  Author: Fakhra Najm<fnajm09@gmail.com>
  * Topic : Map in C++ Standard Template Library (STL)
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
  map<int ,int> MAP;
  // map<int,int>::iterator i; 
  if(MAP.empty()) cout<<"Empty! Please insert some values."<<endl;
  cout<<"map can have a maximum size of "<<MAP.max_size()<<endl;
  MAP.insert(pair<int,int>(0,5));
  MAP.insert(pair<int,int>(1,10));
  MAP.insert(pair<int,int>(2,20));
  MAP.insert(pair<int,int>(3,30));
  MAP.insert(pair<int,int>(4,40));
  MAP.insert(pair<int,int>(5,50));
  cout<<"Good You have inserted "<<MAP.size()<<" elements"<<endl;
  cout<<"Erase first three values that you have inserted"<<endl;
  MAP.erase(MAP.begin(), MAP.find(3));
  cout<<"Insert a value into the map"<<endl;
  MAP.insert({2,20});
  cout<<"key"<<'\t'<<"Value"<<endl;
  for(auto i = MAP.begin(); i != MAP.end(); ++i)
    cout << i->first<<'\t'<< i->second<<endl;

  cout<<"MAP.lower_bound(4) "<<"Value: "<<MAP.lower_bound(4)->second<<endl;
  cout<<"MAP.upper_bound(4) "<<"Value: "<<MAP.upper_bound(4)->second<<endl;
  MAP.clear();
  cout<<"It seems you have cleared the map and it shows "<<MAP.size()<<" size"<<endl;
  
  return 0;
}