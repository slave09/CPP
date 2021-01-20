#include <bits/stdc++.h>
using namespace std;

int main()
{
  map<char, int> winnings;
  int games;
  cin >> games;
  while (games--){
    char chr;
    cin >> chr;
    winnings[chr]++;
  }
  
  if(winnings['A'] > winnings['D']) cout << "Anton" << endl;
  else if(winnings['A'] < winnings['D']) cout << "Danik" << endl;
  else cout << "Friendship" << endl;  
}