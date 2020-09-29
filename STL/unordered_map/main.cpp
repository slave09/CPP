/*
  * Author: Fakhra Najm<fnajm09@gmail.com>
  * Topic: Unordered_map
  * code for Functionality of un_ordered map
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
  unordered_map< int, int> unmap; 
  int key;
  unmap[5] = 5;
  unmap[4] = 4;
  unmap[1] = 1;
  unmap[3] = 3;
  unmap[0] = 0;
  unmap[2] = 2;
  for (auto i = unmap.begin(); i != unmap.end(); i++)
    cout<<i->second << " ";
  cout<<endl<<"Search for key: ";
  cin>>key;
  cout<<"searching "<<key<<"......."<<endl;
  if(unmap.find(key) == unmap.end()) cout<<"Not Found !"<<endl;
  else cout<<"Found !"<<endl;
  return 0;
}