#include <iostream>
using namespace std;

class Item{
	string name;
	float price;
	int quantity;
public:
	Item();
	Item(string name, float price, int quantity);
	Item(Item &item);

	string getName(){return name;}
	float getPrice(){return price;}
	int getQuantity(){return quantity;}

	void setName(string name){this -> name = name;}
	void setPrice(float price){this -> price = price ? price : 0;}
	void setQuantity(int quantity){this -> quantity = quantity ? quantity : 0;}

	friend ofstream & operator<<(ofstream &ofs, Item &item);
	friend ifstream & operator>>(ifstream &ifs, Item &item);
	friend ostream & operator<<(ostream &out, Item &item);

};

Item :: Item(){
	cout << "Please enter product details !" << endl;
}

Item :: Item(string name, float price, int quantity){
	setName(name);
	setPrice(price);
	setQuantity(quantity);
}

Item :: Item(Item &item){
	setName(item.name);
	setPrice(item.price);
	setQuantity(item.quantity);
}

ofstream & operator<<(ofstream &ofs, Item &item){
	ofs << item.name << endl;
	ofs << item.price << endl;
	ofs << item.quantity << endl;

	return ofs;
}

ifstream & operator>>(ifstream &ifs, Item &item){
	ifs >> item.name;
	ifs >> item.price;
	ifs >> item.quantity;

	return ifs;
}

ostream & operator<<(ostream &out, Item &item){
	out << "Name : " << item.name << "\t";
	out << "Price : " << item.price << "\t";
	out << "Quantity : " << item.quantity;

	return out;
}
