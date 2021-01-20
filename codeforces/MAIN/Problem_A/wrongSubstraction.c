/*
  Problem 977A
*/

#include<stdio.h>

int main(){
  int number, times;
  scanf("%d%d",&number, &times);

  for (int i = 0; i < times; i++)
  {
    if(number % 10 == 0)
      number /= 10;
    else
    number -= 1;
  }
  printf("%d", number);
  return 0;
}