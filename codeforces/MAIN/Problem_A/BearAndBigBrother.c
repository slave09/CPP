/*
  problem 791A
*/

#include<stdio.h>

int main(){
  int Limak, Bob, i = 0;
  scanf("%d%d", &Limak, &Bob);
  while(Bob >= Limak){
    Limak *= 3;
    Bob *= 2;
    i++;
  }
  printf("%d",i);
  return 0;
}