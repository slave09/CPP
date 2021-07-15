#include<iostream>
using namespace std;

class DeepTest{
private:
	int size; 
	int *arr;
public: 

	DeepTest(){
		size = 1;
		arr = new int[size];
	}

	DeepTest(int sz){
		setSize(sz);
		setArray();
	}

	DeepTest(DeepTest &test){
		size = test.size;
		// arr = test.arr; // ** This will be pointing to the original arr of test**
		arr = new int[size];

		for(int i = 0; i < size; ++i){
			arr[i] = test.arr[i];
		}
	}

	void setSize(int sz){ 
		if(sz < 0) size = 0;
		else size = sz;
	}

	void setArray(){
		arr = new int [size]; 
		for(int i = 0; i < size; ++i){
			arr[i] = i + 1;
		}
	}

	int GetSize(){return size;}

	void GetArray(){
		for(int i = 0 ; i < size; ++i){
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};


int main(){

	DeepTest test(5);

	cout << "Size : " << test.GetSize() << " ";
	cout << "Array : " ;
	test.GetArray();
	cout << endl;

	DeepTest deep(test);

	cout << "Size : " << deep.GetSize() << " ";
	cout << "Array : " ;
	deep.GetArray();
	cout << endl;

	return 0;
}