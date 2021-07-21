#include<iostream>
using namespace std;

class Diagonal{
	private:
		int *A;
		int n,i,j;
	public:
		Diagonal(){
			A=new int[2];
			n=2;
		}
		Diagonal(int n){
			this->n=n;
			A=new int[2];
		}
		~Diagonal(){
			delete []A;
		}

		int Get(int i,int j);
		void Set(int i,int j,int x);
		void Display();
};

//the matrix is diagonal only if all elements except diagonal elements are zero
//the diagonal index is that where row and column indexes are same  
//so we only have to assign diagonal elements where row and column indexes are same
//one dimensional array is sufficient to store all the diagonal elements

void Diagonal :: Set(int i,int j,int x){
	if(i==j)
		A[i-1]=x;
}

//get function will retrieve the value of given index
//for diagonal matrix all the elements are zero except diagonal element
//thus there is a condition when indexes are not same it will retrieve "0"
//and if indexes are same then it will retrieve values from the one dimensional array

int Diagonal :: Get(int i, int j){
	if (i==j)
		cout<<A[i-1]<<" ";
	else
		cout<<"0 ";
}

//Dispalay function is to print the entire diagonal matrix

void Diagonal :: Display(){
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(i==j)
				cout<<A[i-1]<<" ";
			else
				cout<<"0 ";
		}
		cout<<endl;
	}
}

int main()
{
 int d;
 cout<<"Enter Dimensions";
 cin>>d;

 Diagonal dm(d);

 int x;
 cout<<"Enter All Elements";
 for(int i=1;i<=d;i++)
 {
 for(int j=1;j<=d;j++)
 {
 cin>>x;
 dm.Set(i,j,x);
 }
 }

 dm.Display();
 return 0;
}
