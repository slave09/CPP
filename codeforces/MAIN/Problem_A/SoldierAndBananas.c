/*
Problem 546A
*/

#include<stdio.h>
int main(){
  int price, dollars, banana;
  int sum = 0;
  scanf("%d%d%d", &price, &dollars, &banana); 
  for(int i = 1; i <= banana; i++)
    sum += price*i;
  if(sum > dollars)
    printf("%d", sum-dollars);
  else
    printf("%d", 0);
  return 0;
}