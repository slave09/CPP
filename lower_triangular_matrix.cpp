#include<iostream>

using namespace std;

class lower_triangular_matrix{
	private:
		int *A;
		int n;
	public:
		lower_triangular_matrix(){
			int n=2;
			A=new int[2*(2+1)/2];
		}
		lower_triangular_matrix(int n){
			this->n=n;
			A=new int[n*(n+1)/2];
		}
		~lower_triangular_matrix(){
			delete []A;
		}

		int Get(int i,int j);
		void Set(int i,int j,int x);
		void Display();
		int Get_dimension(){
			return n;
		}
};

//setting the non-zero elements in the array row by row

void lower_triangular_matrix :: Set(int i,int j,int x){
	if(i>=j)
		//if the row index is greater than or equal to column index then the elements in the matrix is non-zero
		//assigning the non-zero elements in the array row by row
		A[i*(i-1)/2+j-1]=x;
}

//it will return the element of the index passed from either created array or will return zero if row index
//is less than column index
int lower_triangular_matrix :: Get(int i,int j){
	if(i>=j)
		return A[i*(i-1)/2+j-1];
	else 
		return 0;
}

//printing all the elements of the class matrix 
void lower_triangular_matrix :: Display(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i>=j)
				cout<<A[i*(i-1)/2+j-1]<<"";
			else
				cout<<"0";
		}
		cout<<endl;
	}
}

int main(){
	int d;
	cout<<"Enter dimension:";
	cin>>d;
	//creating a single-dimensional array to store non-zero elements from the matrix row by row
	lower_triangular_matrix m(d);

	int x;
	cout<<"Enter all elements";

	for(int i=1;i<=d;i++){
		for(int j=1;j<=d;j++){
				cin>>x;
				m.Set(i,j,x);
		}
	}

	cout<<endl;

	m.Display();

	return 0;
}
