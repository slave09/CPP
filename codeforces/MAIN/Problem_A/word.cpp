/*
  Problem 59A
*/

#include<iostream>
#include<cctype>
#include<cstdio>
using namespace std;

int main(){
  char word[101];
  int upper = 0, lower = 0;
  cin>>word;
  for (int i = 0; word[i] != '\0'; i++)
    isupper(word[i]) ? upper++ : lower++;
  for (int i = 0; word[i] != '\0'; i++)
    upper > lower ? putchar(toupper(word[i])) : putchar(tolower(word[i]));
  
  return 0;
}