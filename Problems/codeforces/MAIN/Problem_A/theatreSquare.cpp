/*
  Problem 1A: Theatre Square

 * time limit per test: 1 second
 * memory limit per test : 256 megabytes
 
 
   

    Theatre Square in the capital city of Berland has a rectangular shape with the size n × m meters. 
    On the occasion of the city's anniversary, a decision was taken to pave the Square with square granite 
    flagstones. Each flagstone is of the size a × a.
    What is the least number of flagstones needed to pave the Square? 
    It's allowed to cover the surface larger than the Theatre Square, but the Square has to be covered. 
    It's not allowed to break the flagstones. 
    The sides of flagstones should be parallel to the sides of the Square.
    
 
 
 * Input

  The input contains three positive integer numbers in the first line: n,  m and a (1 ≤  n, m, a ≤ 10^9).
  
  ____________________________________________________________________________________
  
  * Output

  Write the needed number of flagstones.

*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  double m, n, a;
  long long result;
  cin >> m>>n>>a;
  result = ceil(m/a)*ceil(n/a);
  cout << result;
  return 0;
}