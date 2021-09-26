#include<iostream>
using namespace std;
// isSortedFlag is taken to make this algorithm adaptive => when the array is sorted, there will be only one pass
// Bubble sort is stable in itself => no change in order of duplicate numbers
// Stable => That's Why can be used in sorting Records of databases
// Best Case Time => O(n) => for sorted Array
// Worst Case Time => O(n^2)
void bubbleSort(int arr[], int size){
  int isSortedFlag = 0;
  for(int index = 0; index < size; ++index){
    for(int passItr = 0; passItr < size - index - 1; ++passItr){
      if(arr[passItr] > arr[passItr + 1]){
        isSortedFlag = 1;
        swap(arr[passItr], arr[passItr + 1]);
      }
    }
    if(isSortedFlag == 0) return;
  }
}
int main(){
  int Arr[15] = {10,1,2,3,3,2,34,5,6,4,6,7,8,9,10};
  bubbleSort(Arr,15);
  for(auto val : Arr) cout << val << " ";
  cout << endl;
  return 0;
}
