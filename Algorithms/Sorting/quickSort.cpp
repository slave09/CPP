#include<iostream>
using namespace std;

// Taking Last Element as Pivot
// swapping smaller elements to left
int partition(int A[], int low, int high){
  int storeIndex = low;
  for(int index = low; index <= high; ++index){
    if(A[index] < A[high] && storeIndex <= high ){
      swap(A[index], A[storeIndex++]);
    }
  }
  swap(A[storeIndex], A[high]);
  return storeIndex;
}

void quickSort(int A[], int low, int high){
  if(low > high) return;
  int pivot = partition(A, low, high);
  if(pivot >= high) return;
  quickSort(A, low, pivot);
  quickSort(A, pivot + 1, high);
}

int main(){
	int arr[10] = {5,2,3,1,6,8,4,9,7,10};
	quickSort(arr, 0, 9);
	for(auto num : arr) cout << num << " ";
	cout << endl;
	return 0;
}
