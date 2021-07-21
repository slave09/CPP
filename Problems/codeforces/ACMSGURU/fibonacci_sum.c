/*
  * Name  : Fakhra Najm
  * Email : fnajm09@gmail.com
  * Topic : sum of first K fibonacci series
  * First number and Second number of series are 1
  * Constraint : 0 < K < 41
*/

#include<stdio.h>

int main(){

  int first, second, sum, series, K;
  first = second = 1;
  scanf("%d", &K);
  if(K > 0){
    if(K == 1){
      sum = first;
    }
    else{
      sum = first + second;
      for(int i = 0; i < K-2; i++){ 
        series = first + second;
        first = second;
        second = series;
        sum += series;
      }
    }
  }
  printf("%d", sum);
  return 0;
}