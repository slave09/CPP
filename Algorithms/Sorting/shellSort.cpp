#include <iostream>
#include<vector>
using namespace std;

void shellSort(vector<int>&arr){
  int size = arr.size();
  for(int gap = size / 2; gap >= 1; gap /= 2){
    for(int index = gap; index < size; ++index){
      int beginItr = index - gap;
      int currVal = arr[index];
      while(beginItr >= 0 && arr[beginItr] > currVal){
        arr[beginItr + gap] = arr[beginItr];
        beginItr -= gap;
      }
      arr[beginItr + gap] = currVal;
    }
  }
}

int main(){
  vector<int>arr = {11,13,7,12,16,9,24,5,10,3};
  cout << "Array : ";
  for(auto val : arr){
    cout << val << " ";
  }
  shellSort(arr);
  cout << endl << "Sorted Array : ";
  for(auto val : arr){
    cout << val << " ";
  }
  cout << endl;
  return 0;
}