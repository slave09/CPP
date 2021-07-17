#include<iostream>
using namespace std;

class Parent{
private:
	int private_data;
protected:
	int protected_data;
public:
	int public_data;
	Parent(){};
	Parent(int private_data, int protected_data, int public_data);
	~Parent(){}
};

Parent :: Parent(int private_data, int protected_data, int public_data){
	this -> private_data = private_data;
	this -> protected_data = protected_data;
	this -> public_data = public_data;
}


class publicChild : public Parent{
public:
	publicChild(){
		// everything remains as it is
		// public and protected data can be accessed by it's derived class
		// public data can be accessed by it's objects
		cout << "Derived class : publicly inherited" << endl;
		cout << "Protected data is accessible in derived class: " << protected_data << endl;
		cout << "Public data is accessible in derived class : " << public_data << endl;
		cout << "Private data is not accessible in derived class" << endl;		
		cout << "--------------------------" << endl;
	}
};

class protectedChild : protected Parent{
	// everything becomes protected here
	// can be accessed by it's derived class
	// can not be accesed by it's objects
public:
	protectedChild(){
		cout << "Derived class : protectively inherited" << endl;
		cout << "Protected data is accessible in derived class : " << protected_data << endl;
		cout << "Public data is accessible in derived class : " << public_data << endl;
		cout << "Private data is not accessible in derived class" << endl;
		cout << "--------------------------" << endl;		
	}
};

class privateChild : private Parent{
	// everything becomes private here
	// can not be accessible to it's derive class or object
public:
	privateChild(){
		cout << "Derived class : privately inherited" << endl;
		cout << "Protected data is accessible in derived class: " << protected_data << endl;
		cout << "Public data is accessible in derived class : " << public_data << endl;
		cout << "Private data is not accessible in derived class" << endl;	
		cout << "--------------------------" << endl;	
	}
};



class publicGrandChild : public publicChild{
public:
	// private is not accessible 
	// public is accessible as public 
	// protected is accessible as protected
	publicGrandChild(){
		cout << "Derived from publicly inherited" << endl;
		cout << "Public : " << public_data << endl;
		cout << "Protected : " << protected_data << endl;
		cout << "--------------------------" << endl;
	}

};

class protectedGrandChild : public protectedChild{
public:
	// private is not accessible 
	// public is accessible as protected
	// protected is accessible as protected
	protectedGrandChild(){
		cout << "Derived from protectively inherited" << endl;
		cout << "Public : " << public_data << endl;
		cout << "Protected : " << protected_data << endl;
		cout << "--------------------------" << endl;
	}
	
};
class privateGrandChild : public privateChild{
public:
	// private is not accessible 
	// public is not accessible as it becomes private in privateChild
	// protected is not accessible as it becomes private in privateChild
	privateGrandChild(){
		cout << "Derived from privately inherited" << endl;
		cout << "Nothing is accessible in derived class of privately derived parent"<< endl;
		cout << "--------------------------" << endl;
	}
	
};

int main(){
	// Parent parent(5, 10, 15);
	publicChild publicchild;
	privateChild privatechild;
	protectedChild protectedchild;
	publicGrandChild publicgrandchild;
	protectedGrandChild protectedgrandchild;
	privateGrandChild privategrandchild;
	return 0;
}


