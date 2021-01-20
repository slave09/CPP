/*
  Problem 4A: Watermelon
  --------------------------------------------------------------------------------------

    * time limit per test
    1 second

    * memory limit per test
    64 megabytes
    

  Input:

  The first (and the only) input line contains integer number w (1 ≤ w ≤ 100) — the weight of the watermelon bought by the boys.

  ______________________________________________________________________________________________________

  Output:

  Print YES, if the boys can divide the watermelon into two parts, 
  each of them weighing even number of kilos; and NO in the opposite case.
  */

#include <stdio.h>

int main(){
  int weight; // weight of the watermelon
  scanf("%d", &weight);

  // checking if the weight can be divided into two even parts
  if(weight%2==0 && weight/2 != 1)
    printf("YES");
  else
    printf("NO"); 
  return 0;
}