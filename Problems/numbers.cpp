#include <iostream>
#include<cstring>
using namespace std;
 
int main() {
	int test;
	char number[1000001];
	cin>>test;
	while(test--){
		cin>>number;
		cout<<number[0]-'0'+number[strlen(number)-1]-'0'<<" ";
	}
	return 0;