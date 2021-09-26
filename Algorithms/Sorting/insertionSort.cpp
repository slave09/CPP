#include<iostream>
using namespace std;

// Start from the first index assuming that 0th index is sorted i.e. left side of the array is sorted
// For every value start checking from the beginning and shift array if greater elements are found
void insertionSort(int Arr[], int size){
  for(int index = 1; index < size; ++index){
    int val = Arr[index];
    int beginItr = index - 1;
    while(beginItr >= 0 && val < Arr[beginItr]){
      Arr[beginItr + 1] = Arr[beginItr];
      beginItr--;
    }
    Arr[beginItr + 1] = val;
  }
}

int main(){
  int Arr[] = {10,12,3,2,4,45,3,2,3,5};
  int size = sizeof(Arr)/sizeof(Arr[0]);
  insertionSort(Arr,size);
  for(auto val : Arr) cout << val << " ";
  cout << endl;
  return 0;
}
