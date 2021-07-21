/*
	Topic : Namespaces
	* Used tot resolve name conflicts between resources.
	* resources : functions, classes, Objects
	* namespaces can also be a header file
*/

#include <iostream>
using namespace std;

namespace first{
	void Display(){
		cout << "First namespace printed " << endl;
	}
};

namespace second{
	void Display(){
		cout << "Second namspace displayed" << endl;
	}
};

using namespace first;

int main(){

	Display();
	second :: Display();
	return 0;
}