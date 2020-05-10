/*
Name  : Fakhra Najm
Email : fnajm09@gmail.com
swap operator
*/


#include<iostream>
#include<vector>
using namespace std;

void print(vector<int>vect){
  for(auto i : vect){
    cout<<i;
  }
  cout<<endl;
}

int main(){
  vector<int> vect1, vect2;
  vect1.assign(5, 9);
  vect2.assign(10, 7);

  cout<<"first vector : ";
  print(vect1);

  cout<< "second vector : ";
  print(vect2);

  swap(vect1, vect2);
  cout<<"after swapping"<<endl;

  cout<<"first vector : ";
  print(vect1);

  cout<< "second vector : ";
  print(vect2);
  
  return 0;
}