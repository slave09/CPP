/*
  Name  : Fakhra Najm
  Email : fnajm09@gmail.com
          Iterators
*/


#include<iostream>
#include<vector>
using namespace std;

int main(){
  vector <int> V ; 
  for(int i = 0; i < 5; i++)
    V.push_back(i+1);
  
  cout<< "Output :"<<endl;
  for (auto i = V.begin(); i != V.end(); i++)
    cout<< *i <<" " ;

   cout<< endl << "Output using constant iterator :"<<endl;

  for(auto i = V.cbegin(); i != V.cend(); ++i)
    cout<< *i << " " ;

  cout<<endl<< "Reverse output :"<<endl;
  for(auto i = V.rbegin(); i != V.rend(); ++i)
    cout<< *i <<" ";

  cout<<endl<<"Output using constant reverse iterator"<< endl ;

  for(auto i = V.crbegin(); i != V.crend(); ++i)
    cout<< *i << " ";
  return 0;
}