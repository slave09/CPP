/*
  Problem 116A
*/

#include<stdio.h>

int main(){
  int stops, enter, exit, capacity, insider = 0;
  scanf("%d", &stops);

  int *passengers = (int *)malloc((stops-1)*sizeof(int));

  for (int i = 0; i < stops-1; i++)
  {
    scanf("%d%d", &exit, &enter);
    passengers[i] = insider - exit + enter;
    insider = passengers[i];
  }

  capacity = passengers[0];

  for(int i = 1; i < stops-1; i++){
    if(capacity < passengers[i])
      capacity = passengers[i];
  }

  printf("%d", capacity);
  return 0;
  
}