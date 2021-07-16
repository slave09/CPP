/*
	Write a C++ class of Students with : 
		1. Name
		2. Roll
		3. Marks in 3 Subject
	Functions for : 
		1. Total Marks
		2. Grade
		3. Any Required Method
*/

#include<iostream>
using namespace std;

class Students{
	int Roll;
	string Name;
	int *Marks;

public:
	Students();
	Students(string Name, int Roll, int Marks[]);
	Students(Students &student);

	void setName(string Name);
	void setRoll(int Roll);
	void setMarks(int Marks[]);

	string getName(){return Name;}
	int getRoll(){return Roll;} 
	int* getMarks(){return Marks;}

	float total_marks();
	float percentage();
	char grade();

	bool isPass();

	~Students();
};

int main(){

	string Name;
	int Marks[3];
	int Roll;

	cout << "Enter Name : " << endl;
	cin >> Name;

	cout << "Enter Roll : " << endl;
	cin >> Roll ;


	for(int subject = 0; subject < 3; ++subject){
		cout << "Marks of subject " << subject  + 1 << " : " << endl;
		cin >> Marks[subject];
	}

	Students student(Name, Roll, Marks);
	cout << "_____________________________________\n";
	cout << "Name : " << student.getName() << endl;
	cout << "Roll : " << student.getRoll() << endl;
	cout << "Percentage : " << student.percentage() << "%"<< endl;
	cout << "Total Marks Obtained : " << student.total_marks() << endl;
	cout << "Grade : " << student.grade() << endl; 

	if(student.isPass())
		cout << "PASSED :)" << endl;

	else cout << "FAILED !!!" << endl;

	return 0;
}

Students :: Students(){
	int marks[3] = {0};
	setName("none");
	setRoll(0);
	setMarks(marks);
}

Students :: Students(string Name, int Roll, int Marks[]){
	setName(Name);
	setRoll(Roll);
	setMarks(Marks);
}

Students :: Students(Students &student){
	setName(student.Name);
	setRoll(student.Roll);
	setMarks(student.Marks);
}


void Students :: setName(string Name){
	if(Name == " ") cout << "Enter Valid Name !" << endl;
	else this -> Name = Name;
}

void Students :: setRoll(int Roll){
	if(Roll <= 0) cout << "Enter Valid Roll !" << endl;
	else this -> Roll = Roll;
}

void Students :: setMarks(int Marks[]){
	this -> Marks = new int[3];

	for(int i = 0; i < 3; ++i){
		this -> Marks[i] = Marks[i];
	}

}

float Students :: total_marks(){
	float total = 0;
	for(int i = 0; i < 3; ++i){
		total += Marks[i];
	}
	return total;
}

float Students :: percentage(){
	float student_total_marks = total_marks();
	return (student_total_marks * 100) / 300;
}

char Students :: grade(){
	if(percentage() >= 30 && percentage() < 40) return 'C';
	else if(percentage() < 60 && percentage() > 40) return 'B';
	else if(percentage() > 60) return 'A';
	else return 'F';
}

bool Students :: isPass(){
	if( grade() == 'A' || grade() == 'B' || grade() == 'C') return true;
	else return false;
}

Students :: ~Students(){
	delete []Marks;
}


