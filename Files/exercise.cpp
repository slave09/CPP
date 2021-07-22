#include<iostream>
#include<fstream>
#include "exercise.h"
using namespace std;

int main(){
	int total_items;
	float item_price;
	string item_name;
	int item_quantity;

	cout << "Enter total number of items : " << endl;
	cin >> total_items;

	Item *items_list[total_items];

	for(int i = 0; i < total_items; ++i){
		cout << "Item " << i + 1 << " Details:- " << endl;
		cout << "Name : " ;
		cin >> item_name;
		cout << "Price : ";
		cin >> item_price;
		cout << "Quantity : ";
		cin >> item_quantity;
		items_list[i] = new Item(item_name, item_price, item_quantity);
	}

	ofstream itemFile("item.txt");
	for(int i = 0; i < total_items; ++i){
		itemFile << *items_list[i];
	}
	itemFile.close();

	ifstream item;
	item.open("item.txt");
	if(item){
		Item item_details;
		cout << "Your Details :-" << endl;
		for(int i = 0; i < total_items; ++i){
			item >> item_details;
			cout << "Item Number " << i + 1 << "\t";
			cout <<  item_details << endl;
		}
	}

	return 0;
}