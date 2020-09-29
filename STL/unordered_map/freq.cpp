/*
  * Author: Fakhra Najm<fnajm09@gmail.com>
  * C++ program to find freq of every word using 
  * unordered_map 
*/

#include<bits/stdc++.h>
using namespace std;

void frequencies(string &sentence){
  unordered_map <string , int> freq;
  stringstream ss(sentence);
  string word;
  while(ss >> word)
    freq[word]++;
  for(auto i = freq.begin(); i != freq.end(); ++i){
    cout << i->first;
    cout<<" ";
    cout<<i->second<<endl;
  }
}

int main(){
  string sentence = "Don't repeat yourself again and again";
  frequencies(sentence);
  return 0;
}