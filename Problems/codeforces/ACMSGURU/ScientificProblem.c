/*
  Author: Fakhra Najm
  Email: fnajm09@gmail.com
  Topic: Scientific problem
  __________________________________________________________________________________________________
  Problem: Once upon a time Professor Idioticideasinventor was travelling by train. 
  Watching cheerless landscape outside the window, he decided to invent the theme of his new scientific work.
  All of a sudden a brilliant idea struck him: to develop an effective algorithm finding an integer number, 
  which is x times less than the sum of all its integer positive predecessors, where number x is given. 
  As far as he has no computer in the train, you have to solve this difficult problem.
  *******************************************************************************
  Time limit per test: 0.25 second(s)
  Memory limit: 65536 kilobytes
  input: standard
  output: standard
  *******************************************************************************

  Sample input             Sample Output
      1                         3
      2                         5
      3                         7
      4                         9
      _ ________

      x                        ((2*x)+1)
*/

#include <stdio.h>

int main(){
  int x;
  scanf("%d", &x);
  printf("%lld", (2*(x) + 1));
  return 0;
}