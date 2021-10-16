#include<iostream>
#include<vector>
#include <climits>
using namespace std;

class CountSort{
  vector<int>elementCount;
public:
  CountSort(vector<int>&vec);
  int findMax(vector<int>&vec);
  void refillVector(vector<int>&vec);
};

int main(){
  vector<int>arr = {1,4,3,5,3,4,6,7,6,5,3,2};
  CountSort count_sort(arr);
  for(auto val : arr) cout << val << " ";
  cout << endl;
  return 0;
}

CountSort :: CountSort(vector<int>&vec){
  int maxValue = findMax(vec);
  elementCount.resize(maxValue + 1);
  for(int index = 0; index < elementCount.size(); ++index){
    elementCount[index] = 0;
  }
  for(int key = 0; key < vec.size(); ++key){
    elementCount[vec[key]]++;
  }
  refillVector(vec);
}

int CountSort :: findMax(vector<int>&vec){
  int maxElement = INT_MIN;
  for(auto val : vec){
    maxElement = max(maxElement, val);
  }
  return maxElement;
}

void CountSort :: refillVector(vector<int>&vec){
  int vecItr = 0;
  int countItr = 0;
  while(countItr < elementCount.size()){
    if(elementCount[countItr] > 0){
      vec[vecItr++] = countItr;
      elementCount[countItr]--; 
    }
    else{
      countItr++;
    }
  }
}
