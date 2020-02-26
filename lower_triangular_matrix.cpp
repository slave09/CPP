#include<iostream>

using namespace std;

class lower_triangular_matrix{
	private:
		int *A;
		int n;
	public:
		lower_triangular_matrix(){
			int n=2;
			A=new int[2];
		}
		lower_triangular_matrix(int n){
			int this->n=n;
			A=new int[n];
		}
		~lower_triangular_matrix(){
			delete []A;
		}

		int Get(int i,int j);
		void Set(int i,int j,int x);
		void Display();
		void Get_dimension(){
			return n;
		}
};

void lower_triangular_matrix :: Set(int i,int j,int x){
	if(i>=j)
		A[i*(i-1)/2+j-1]=x;
}

int lower_triangular_matrix :: Get(int i,int j){
	if(i>=j)
		return A[i*(i-1)/2+j-1];
	else 
		return 0;
}

void lower_triangular_matrix :: Display(){
	for(int i=1;i<=d,i++){
		for(int j=1;j<=d;j++){
			if(i>=j)
				cout<<A[i*(i-1)/2+j-1]<<"";
			else
				cout<<"0";
		}
		cout<<endl;
	}
}

int main(){
	class lower_triangular_matrix m;
	cout<<"Enter dimension:";
	cin>>d;

	int x;
	cout<<"Enter all elements";

	for(int i=1;i<=d;i++){
		for(int j=1;j<=d;j++){
			if(i>=j)
				cin>>x;
				Set(i,j,x);
		}
	}

	cout<<endl;

	Display();

	return 0;
}
