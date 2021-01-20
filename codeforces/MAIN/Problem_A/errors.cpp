#include <bits/stdc++.h>
using namespace std;

int sum(int size){
  int result = 0;
  while(size --){
    int num;
    cin >> num;
    result += num;
  }
  return result;
}

int main(){
  int total_errors;
  cin >> total_errors;
  int total_sum = sum(total_errors);
  int one_solved = sum(total_errors - 1);
  int two_solved = sum(total_errors - 2);
  cout << total_sum - one_solved << endl << one_solved - two_solved << endl ;
  return 0;
}