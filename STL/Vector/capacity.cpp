/*
  Name  : Fakhra Najm
  Email : fnajm09@gmail.com
  * Vector capacity
*/

#include<iostream>
#include<vector>
using  namespace std;

int main(){

  vector <int> V(5) ;
  cout<<"Capacity is "<< V.capacity()<< endl;
  cout<<"size is "<< V.size()<< endl;
  cout<<"maximum size is "<< V.max_size()<<endl;

//Resize

  V.resize(10);
  cout<<"New size is "<< V.size()<< endl;
  cout<<"Capacity is "<< V.capacity()<< endl;
  V.resize(11);
  cout<<"New size is "<< V.size()<< endl;
  cout<<"Capacity is "<< V.capacity()<< endl;

//shrink

  V.shrink_to_fit();
  cout<<"Capacity is "<< V.capacity()<< endl;

//Reserve

  V.reserve(10);
  cout<<"Capacity is "<< V.capacity()<< endl;
  V.resize(5);
  cout<<"New size is "<<V.size()<< endl;
  cout<<"Capacity is "<<V.capacity()<< endl;

//empty

  if(V.empty() == true ){
    cout<<"vector is empty";
  }
  else {
    cout << "vector is not empty";
  }

  return 0;
}