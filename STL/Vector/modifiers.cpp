/*
  Name  : Fakhra Najm
  Email : fnajm09@gmail.com
  Modifying vectors
*/

#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> V){
  for (auto i : V) {
    cout << i << " ";
  }
  cout<<endl;
}

int main(){
  vector <int> V;

  V.assign(5, 9);
  cout<< "initially:"<<endl;
  print(V);

  V.push_back(10);

  cout<<"finally"<< endl;
  print(V);

  cout<<"Rear Value:"<< V.back()<<endl;

  V.pop_back();
  cout<<"after pop_back(): ";
  print(V);

  V.insert(V.end(), 7);
  cout << "after insertion"<<endl;
  print(V);

  V.pop_back();
  cout<<"After erasing "<<endl;
  print(V);

  V.emplace(V.begin(), 7);
  V.emplace_back(7);
   cout<<"After emplacing "<<endl;
  print(V);

  V.erase(V.begin());
  cout<< "after erasing front element"<<endl;

  print(V);
  V.clear();
  cout<<"size of vector in end : "<<V.size();

  return 0;
}
