#include<iostream>
using namespace std;

class Student{
	int roll;
	string name;
	static int addmission_id;
public:
	Student();
	Student(string name);
	Student(Student &student);

	int getRoll(){return roll;}
	string getName(){return name;}
	static int getAddmissionId(){return addmission_id;}

	void setRoll();
	void setName(string name);

	~Student(){}

};

Student :: Student(){
	cout << "Please Enter Student Details !" << endl;
}


Student :: Student(string name){
	addmission_id++;
	setName(name);
	setRoll();
}

Student :: Student(Student &student){
	setName(student.name);
	setRoll();
	addmission_id++;
}

void Student :: setName(string name){
	if(name == " ") cout << "Enter Valid Name" << endl;
	else this -> name = name;
}


void Student :: setRoll(){
	roll = addmission_id;
}

int Student :: addmission_id = 0;


int main(){
	Student student[5];

	for(int i = 0; i < 5; ++i){
		string name;
		cout << "Enter Student Name" << endl;
		cin >> name;
		Student candidate(name);
		student[i] = candidate;
	}

	cout << "---------------------------" << endl;

	for(int i = 0; i < 5; ++i){
		cout << "Student Name : " << student[i].getName() << "\t";
		cout << "Student Roll : " << student[i].getRoll() << endl;
	}

	cout << "---------------------------" << endl;

	cout << "Total students : " << Student :: getAddmissionId() << endl;

	return 0;
}