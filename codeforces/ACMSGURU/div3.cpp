/*
  Author: Fakhra Najm
  Email:  fnajm09@gmail.com

  Problem: There is sequence 1, 12, 123, 1234, ..., 12345678910, ... . 
  Given first N elements of that sequence.
  determine amount of numbers in it that are divisible by 3. 

  * time limit per test: 0.25 sec.
  * memory limit per test: 4096 KB 
  ********************************************************************
  
  * Input

    Input contains N (1<=N<=2^31 - 1).
______________________________________
  * Output

    Write answer to the output. 



*/

#include <iostream>

using namespace std;

int main()
{
  int number;
  int remainder;
  cin >> number;

  remainder = number%3;

  if(remainder == 0 || remainder == 1){
    cout<< (number/3)*2;
  }
  else if (remainder == 2){
    cout<< (number/3)*2 + 1;
  }

  return 0;
}
