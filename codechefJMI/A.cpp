#include<bits/stdc++.h>
using namespace std;

int main(){
  unordered_set<string>s;
  string str;
  cin>>str;
  for(int i = 0; i < str.size(); ++i ){
    string temp = str;                                                                                                                        
    for(int j = 0; j <= i; j++ ){
      swap(str[i],str[j]);
      s.insert(str);
      str = temp;
    }
  }
  cout<<s.size()<<endl;
  return 0;
}