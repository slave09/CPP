#include<iostream>
using namespace std;

int partition(int arr[], int low, int high){
	int pivot = arr[low];
	int i = low, j = high;

	while(i < j){
		do{i++;}while(pivot >= arr[i]);
		do{j--;}while(pivot < arr[j]);
		if(i < j) swap(arr[j], arr[i]);
	}
	swap(arr[j], arr[low]);
	return j;
}

void quickSort(int arr[],int low ,int high){
	if(low < high){
		int pivot = partition(arr, low, high);
		quickSort(arr, low, pivot);
		quickSort(arr, pivot + 1, high);
	}
}

int main(){
	int arr[9] = {6,5,8,9,3,10,15,12,16};
	quickSort(arr, 0, 8);

	for(auto num : arr) cout << num << " ";
	cout << endl;

	return 0;
}