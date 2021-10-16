#include<iostream>
#include<vector>
#include<climits>
#include<math.h>
using namespace std;

class Node{
protected:
  int val;
  Node *next;
  void insert(vector<Node*>&radixBucket, int val, int index);
  int deleteNode(vector<Node*>&radixBucket, int index);
public:
  Node(){}
  Node(int val){this -> val = val;}
  int getVal(){return this -> val;}
};

class RadixSort : protected Node{
  vector<Node*> radixBucket;
  void refillVector(vector<int>&arr);
  int getNthPlaceValue(int val, int n);
  int findMaxValue(vector<int>&arr);
  int findMaximumDigits(int val);
  void initializeBucket();
public:
  RadixSort(vector<int>&arr);
  ~RadixSort();
};

int main(){
  vector<int>arr = {20,1,2,3,4,5,67,11,6,5,4,3,8,7,6,45,80,50};
  RadixSort sort(arr);
  for(auto val : arr)
    cout << val << " ";
  cout << endl;
  return 0;
}

void Node :: insert(vector<Node*>&radixBucket, int val, int index){
  if(radixBucket[index] == NULL){
    radixBucket[index] = new Node(val);
    return;
  }
  Node *radixBucketItr = radixBucket[index];
  while(radixBucketItr -> next){
    radixBucketItr = radixBucketItr -> next;
  }
  radixBucketItr -> next = new Node(val);

}

int Node :: deleteNode(vector<Node*>&radixBucket, int index){
  if(!radixBucket[index]) return INT_MIN;
  Node *temp = radixBucket[index];
  int val = temp -> val;
  radixBucket[index] = temp -> next;
  delete temp;
  return val;
}

RadixSort :: RadixSort(vector<int>&arr){
  initializeBucket();
  int maxDigits = findMaximumDigits(findMaxValue(arr));
  for(int index = 0; index < maxDigits; ++index){
    for(int key = 0; key < arr.size(); ++key){
      insert(radixBucket, arr[key], getNthPlaceValue(arr[key], index));
    }
    refillVector(arr);
    initializeBucket();
  }
}

void RadixSort :: initializeBucket(){
  radixBucket.resize(10);
  for(int index = 0; index < 10; ++index){
    radixBucket[index] = NULL;
  }
}

int RadixSort :: findMaxValue(vector<int>&arr){
  int maxValue = INT_MIN;
  for(int index = 0; index < arr.size(); ++index){
    maxValue = max(maxValue, arr[index]);
  }
  return maxValue;
}

int RadixSort :: findMaximumDigits(int val){
  int digits = 0;
  while(val != 0){
    digits ++;
    val /= 10;
  }
  return digits;
}

int RadixSort :: getNthPlaceValue(int val, int n){
  val = val / (pow(10, n));
  return val % 10;
}

void RadixSort :: refillVector(vector<int>&arr){
  for(int index = 0, key = 0; index < radixBucket.size(); ++index){
    while(radixBucket[index]){
      int val = deleteNode(radixBucket, index);
      if(val == INT_MIN) continue;
      arr[key++] = val; 
    }
  }
}

RadixSort :: ~RadixSort(){
  for(int index = 0; index < radixBucket.size(); ++index){
    delete radixBucket[index];
  }
}