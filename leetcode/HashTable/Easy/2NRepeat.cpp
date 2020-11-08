#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int repeatedNTimes(vector<int> &A)
  {
    map<int, int> map;
    for (int i = 0; i < A.size(); ++i)
    {
      map[A[i]]++;
      if (map[A[i]] > 1)
        return A[i];
    }
    return -1;
  }
};

/*
  * Another apparoach
  * here repeated numbers = n-1
  * non-repeated numbers = n+1
  * arranging (n+1) and (n-1) numbers will be at least alternate or side by side.
*/

class Solution
{
public:
  int repeatedNTimes(vector<int> &A)
  {
    for(int i = 0; i < A.size()-2; i++)
      if(A[i] == A[i+1] || A[i] == A[i+2]) return A[i];
    return A[A.size() - 1];
  }
};