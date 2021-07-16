#include<iostream>
using namespace std;

class Test{
	string Name;
	int Marks;

public:

	Test();
	Test(string name, int marks);
	Test(Test &test);

	inline void setName(string name); // inline function with implementation outside of the class 
	inline void setMarks(int marks); // inline function with implementation outside of the class 

	string getName(){return Name;} // inline function implemented inside the class
	int getMarks(){return Marks;} // inline function implemented inside the class

	~Test();

};

int main(){
	Test test;
	test.setName("Najm");
	test.setMarks(85);

	cout << "Name : " << test.getName() << endl;
	cout << "Marks : " << test.getMarks() << endl;

	return 0;
}

Test :: Test(){
	setName("none");
	setMarks(0);
}

Test :: Test(string name, int marks){
	setName(name);
	setMarks(marks);
}

Test :: Test(Test &test){
	setName(test.Name);
	setMarks(test.Marks);
}

void Test :: setName(string name){
	if(name == " ") Name = "none";
	else Name = name;
}

void Test :: setMarks(int marks){
	if(Name == "") Marks = 0;
	else Marks = marks;
}

Test :: ~Test(){}