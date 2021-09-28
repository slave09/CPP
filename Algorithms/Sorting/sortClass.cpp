#include<iostream>
#include<vector>
using namespace std;

class Sort{
  int size;
  vector<int> array;
public:
  Sort(vector<int> arr);
  int getSize(){return this -> size;}
  void bubbleSort();
  void insertionSort();
  void selectionSort();
  void quickSort(int low, int high);
  int partitionIndex(int low, int high, int pivot);
  void merge(int low, int high, int mid);
  void mergeSort(int low, int high);
  void print();
};

int main(){
  Sort Arr({22,23,34,56,67,68,69,88,89,99});
  Arr.mergeSort(0,9);
  Arr.print();
  return 0;
}

Sort :: Sort(std::vector<int> arr){
  size = arr.size();
  this -> array = arr;
}

void Sort :: print(){
  for(auto val : array){
    cout << val << " ";
  }
  cout << endl;
}

void Sort :: bubbleSort(){
  int isSortedArray = 0;
  for(int index = 0; index < size; ++index){
    for(int passItr = 0; passItr < size - index - 1; ++passItr){
      if(array[passItr] > array[passItr + 1]){
        swap(array[passItr], array[passItr + 1]);
        isSortedArray = 1;
      }
    }
    if(isSortedArray == 0) return;
  }
}

void Sort :: insertionSort(){
  for(int index = 1; index < size; ++index){
    int val = array[index];
    int beginItr = index - 1;
    while(beginItr >= 0 && array[beginItr] > val){
      array[beginItr + 1] = array[beginItr];
      beginItr--;
    }
    array[beginItr + 1] = val;
  }
}

void Sort :: selectionSort(){ // (n - 1) passes are required  
  for(int index = 0; index < size - 1; ++index){
    int minValIndex = index;
    for(int beginItr = minValIndex; beginItr < size; ++beginItr){
      if(array[minValIndex] > array[beginItr]){
        minValIndex = beginItr;
      }
    }
    swap(array[minValIndex], array[index]);
  }
}

int Sort :: partitionIndex(int low, int high, int pivot){
  swap(array[pivot], array[high]);
  int storeIndex = low;
  for(int index = low; index <= high; ++index){
    if(array[high] > array[index]){
      swap(this -> array[index], this -> array[storeIndex++]);
    }
  }
  swap(this -> array[high], this -> array[storeIndex]);
  return storeIndex;
}

void Sort :: quickSort(int low, int high){
  if(low > high) return;

  int pivot = low + rand() % (high - low + 1);
  pivot = partitionIndex(low, high, pivot);
  if(pivot > high) return;
  quickSort(low, pivot - 1);
  quickSort(pivot + 1, high);
}

void Sort :: merge(int low, int high, int mid){
  vector<int>meregedArray(high + 1);
  int left, right, storeIndex;
  left = storeIndex = low;
  right = mid + 1;

  while(left <= mid && right <= high){
    if(array[left] < array[right]){
      meregedArray[storeIndex++] = array[left++];
    }
    else{
      meregedArray[storeIndex++] = array[right++];
    }
  }
  while(left <= mid){
    meregedArray[storeIndex++] = array[left++];
  }
  while(right <= high){
    meregedArray[storeIndex++] = array[right++];
  }
  for(int index = low; index <= high; ++index){
    array[index] = meregedArray[index];
  }
}

void Sort :: mergeSort(int low, int high){
  if(low < high){
    int mid = low + (high - low) / 2;
    mergeSort(low, mid);
    mergeSort(mid + 1, high);
    merge(low, high, mid);
  }
}