/*
  Author: Fakhra Najm
  Email:  fnajm09@gmail.com
  _______________________________________________________________________________________
  Problem:  For given integer N (1<=N<=10^4) find amount of positive numbers not greater than N that coprime with N. 
  Let us call two positive integers (say, A and B, for example) coprime if (and only if) 
  their greatest common divisor is 1. (i.e. A and B are coprime iff gcd(A,B) = 1).

  *************************************************************************************
  Solution: 1. start with i = 1 check if it is less than the given number (say the number n)
            a. take gcd(1,n)
            b. if GCD = 1, count that number 
            c. else increment i
            2. return count of number 

*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  int coprime = 0;
  cin>>n;

  if (n == 1 || n == 2)
    coprime += 1;

  else{
    int i = 1;

    while (i < n)
    {
      if(__gcd(i,n) == 1)
        coprime++;
      i++;
    }   
  }

  cout<<coprime;
  cout<<endl;

  return 0;
}
