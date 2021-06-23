#include<iostream>
using namespace std;

int main(){
	int layers;
	cin >> layers;

	if(layers == 1) cout << "I hate it ";
	else{
		for(int layer = 1; layer <= layers; ++layer){
			if(layer % 2){
				if(layer == layers) cout << "I hate it ";
				else cout << "I hate that ";
			} 
			else{
				if(layer == layers) cout << "I love it ";
				else cout << "I love that ";
			}
		}
	}
	
	return 0;
}