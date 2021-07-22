#include <iostream>
#include <fstream>
using namespace std;

class Students{
	string firstName;
	string lastName;
	int roll;
	string stream;
public:
	Students();
	Students(string firstName, string lastName, int roll, string stream);
	Students(Students &student);

	string getFirstName(){return firstName;}
	string getLastName(){return lastName;}
	int getRoll(){return roll;}
	string getStream(){return stream;}

	void setFirstName(string firstName){this -> firstName = firstName;}
	void setLastName(string lastName){this -> lastName = lastName;}
	void setRoll(int roll);
	void setStream(string stream){this -> stream = stream;}

	friend ofstream & operator<<(ofstream &out, Students &student);
	friend ifstream & operator>>(ifstream &in, Students &student);
	friend ostream & operator<<(ostream &out, Students &student);
};

Students :: Students(){
	cout << "Please Enter Students Details" << endl;
}

Students :: Students(string firstName, string lastName, int roll, string stream){
	setFirstName(firstName);
	setLastName(lastName);
	setRoll(roll);
	setStream(stream);
}

Students :: Students(Students &student){
	setFirstName(student.firstName);
	setLastName(student.lastName);
	setRoll(student.roll);
	setStream(student.stream);
}

void Students :: setRoll(int roll){
	if(roll < 0) cout << "Roll cannot be negative" << endl;
	else this -> roll = roll;
} 

ofstream & operator<<(ofstream &out, Students &student){
	out << student.firstName << " " << student.lastName << endl;
	out << student.roll << endl;
	out << student.stream << endl;
	return out;
}

ifstream & operator>>(ifstream &in, Students &student){
	in >> student.firstName;
	in >> student.lastName;
	in >> student.roll;
	in >> student.stream;

	return in;
}

ostream & operator<<(ostream &out, Students &student){
	cout << student.firstName << " " ;
	cout << student.lastName << endl;
	cout << student.roll << endl ;
	cout << student.stream << endl ;

	return out;
}

int main(){

	Students student("Fakhra", "Najm", 27, "B.Tech");

	ofstream details("student_details.txt");
	details << student ;
	details.close();

	ifstream file;
	file.open("student_details.txt");

	if(file){
		Students newbie;
		file >> newbie;
		cout << newbie ;
	}


	return 0;
}