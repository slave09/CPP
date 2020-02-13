#include<iostream>
using namespace std;

class Array{
	private:
		int *A;
		int length;
		int size;
	public:
		Array()
		{
			size=10;
			A=new int[size];
			length=0;
		}

		Array(int sz)
		{
			size=sz;
			A=new int[size];
			length=0;
		}

		~Array()
		{
			delete []A;
		}

		void Display();
		void Insert(int index,int x);
		int Delete(int index);
};

void Array :: Display(){
	for(int i=0;i<length;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

void Array :: Insert(int index,int x){
	if(index>=0 && index<=length){
		for (int i = length; i >= index; i--)
			A[i]=A[i-1];
		A[index]=x;
		length++;
	}
}

int Array :: Delete(int index){
	int x=0;
	if(index>=0 && index<length){
		x=A[index];
		for (int i = index; i < length-1; i++)
			A[i]=A[i+1];
	    length--;
		return x;
	}
	return 0;
}

int main(){
	Array arr(10);
	arr.Insert(0,5);
	arr.Insert(1,10);
	arr.Insert(2,15);
	arr.Insert(3,20);
	arr.Insert(4,25);
	arr.Display();
	cout<<arr.Delete(4)<<"is deleted";
	cout<<endl;
	arr.Display();
	return 0;
}
