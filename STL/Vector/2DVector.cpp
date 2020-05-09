/*
  * Name  : Fakhra Najm  
  * Email : fnajm09@gmail.com
  * Two dimensional vectors
*/

#include<iostream>
#include<vector>
using namespace std;

int main(){
  vector < vector<int> > vect{{1, 2, 3},
                              {4, 5, 6},
                              {7, 8, 9}};
                        
  cout << "created vector: "<<endl;                      
  for(int i = 0; i < vect.size(); i++){
    for(int j = 0; j < vect[i].size(); j++){
      cout<< vect[i][j] << " ";
    }
    cout<<endl;
  }
  
  int n,m;
  cout<<  "Enter number of rows:"<<" ";
  cin>>m;

  cout<<  "Enter number of columns:"<<" ";
  cin>>n;

  cout<< "Now creating vector"<<m<<"*"<<n<<"vector";

  vector<vector<int> > vec( m , vector<int>(n) );  

  cout<<endl<<"Enter all values of 2d-vector";

  for(int i = 0; i < m; ++i ){
    for(int j = 0; j < n; j++){
      cin>>vec[i][j];
    }
  }

  cout<< "Output:"<<endl;
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      cout<<vec[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;

}