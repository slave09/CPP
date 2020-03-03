#include<iostream>
using namespace std;

//class of Element which contains row index as i,column index as j and the number itself as x

class Element 
{
	public:
		int i;
		int j;
		int x;

};

//class of Sparse Matrix which contains the total number of non-zero rows,column and number as m,n,num respectively
//Sparse is pointing on element so that it can uphold all the element's Data of non-zero element

class Sparse
{
	private:
		int m;
		int n;
		int num;
		struct Element *e;
	public:
		Sparse(int m,int n,int num){
			this->m=m;
			this->n=n;
			this->num=num;
			e=new Element[this->num];
		}

		~ Sparse(){
			delete []e;
		}

		Sparse operator+(Sparse &s);

		friend istream & operator>>(istream &is,Sparse &s );
		friend ostream & operator<<(ostream &os,Sparse &s );
};

istream & operator>>(istream &is,Sparse &s ){
	cout<<"Enter All of non-zero elements";
		for(int i=0;i<s.num;i++){
	    	cin>>s.e[i].i>>s.e[i].j>>s.e[i].x;			
	    }
	}

ostream & operator<<(ostream &os,Sparse &s ){
	int k=0;
	for(int i=0;i<s.m;i++){
		for(int j=0;j<s.n;j++){
			if(i==s.e[k].i && j==s.e[k].j)
				printf("%d ",s.e[k++].x );
				else
					printf("0 ");
				}
			cout<<endl;
		}
	}

Sparse Sparse :: operator+(Sparse &s){
	int i,j,k;
	i=j=k=0;
	Sparse *sum=new Sparse(m,n,num+s.num);

	while(i<num && j<s.num){
		if(e[i].i<s.e[j].i){
			sum->e[k++]=e[i++];
		}
		else if(e[i].i>s.e[j].i){
			sum->e[k++]=s.e[j++];
		}
		else{
			if(e[i].j>s.e[j].j){
				sum->e[k++]=s.e[j++];
			}
			else if(e[i].j<s.e[j].j){
				sum->e[k++]=e[i++];
			}
			else{
				sum->e[k]=s.e[j];
				sum->e[k++].x=e[i++].x+s.e[j++].x;
			}
		}
	}
	for(;i<num;i++) {
		sum->e[k++]=e[i++];
	}
	for(;j<s.num;j++){ 
		sum->e[k++]=s.e[j++];
	}

	sum->m=m;
	sum->n=n;
	sum->num=k;

	return *sum;

}



int main(){
    Sparse s1(5,5,5),s2(5,5,5);
	cin>>s1;
	cin>>s2;
	cout<<"First Matrix"<<endl<<s1;
	cout<<"Second Matrix"<<endl<<s2;
	Sparse sum=s1+s2;
	cout<<"Sum Matrix"<<endl<<sum;
	cout<<endl;
	cout<<"Sparse Matrix is represented above";
	return 0;
}
