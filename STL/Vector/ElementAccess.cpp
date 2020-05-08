/*
  Name  : FAKHRA NAJM
  Email : fnajm09@gmail.com
  * Accesing elements of vector
*/

#include<iostream>
#include<vector>
using namespace std;

int main(){
  //vector using array
  vector <int> V{10, 15, 20, 25, 30},B{10,20,30,40,50};

  cout<<"Vector V :";
  for(auto i : V){
    cout<< i << " ";
  }
  cout<< endl;
  cout<<"Vector B :";
  for(auto j = 0; j< B.size(); ++j){
    cout<< B.at(j) << " "; 
  }

  cout << endl << "Reference operator at index 0 :"<< V[0];
  cout<<endl<< "Front: "<< V.front();
  cout<<endl<< "Rear: "<< V.back();
  int *pointer = V.data();
  cout<< endl <<"front pointer is "<<V.data();

  return 0;
}