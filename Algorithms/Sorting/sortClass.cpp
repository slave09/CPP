#include<iostream>
using namespace std;
#include<vector>

class Sort{
  int size;
  vector<int> array;
public:
  Sort(std::vector<int> arr);
  int getSize(){return this -> size;}
  void bubbleSort();
  void insertionSort();
  void quickSort(int low, int high);
  int partitionIndex(int low, int high);
  void print();
};

int main(){
  Sort Arr({1,2,3,4,45,6,5,4,3,22});
  Arr.insertionSort();
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

int Sort :: partitionIndex(int low, int high){
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
  int pivot = partitionIndex(low, high);
  if(pivot > high) return;
  quickSort(low, pivot - 1);
  quickSort(pivot + 1, high);
}
