/*
  Author: Fakhra Najm<fnajm09@gmail.com>
  * Topic: Parenthesis matching
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
  stack<char> stk;
  char values[100];
  cout << "Enter Expression: ";
  cin>>values;
  int length = strlen(values);
  for (int i = 0; i < length; i++)
  {
    if(values[i] == '(')
      stk.push('(');
    else if(stk.empty()) {
      cout<<"Not Balanced!"<<endl;
      return -1;
    }
    else if(values[i] == ')')
      stk.pop();
  }
  if(stk.empty()) cout<<"Balanced"<<endl;
  return 0;
}