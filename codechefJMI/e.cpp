#include <bits/stdc++.h>
using namespace std;

int main(){
	map <int ,int> m1;
  int people, birth, death;
	int counter = 0, alive = 0, year;
  cin >> people;
  while(cin>>birth && cin>>death)
    m1[birth] ++ , m1[death] --;
  for(auto &i : m1){
  	counter += i.second;
  	if(counter > alive) year = i.first;
  	alive = max(counter, alive);
  }
  cout << year << " " << alive << endl;
  return 0;
}