/*
	* Problem : Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
	* apparoach : sort all the items on basis of 'VALUE PER UNIT' and add whole item if it's weight is less than capacity otherwise
	add the portion of that item.
*/

#include <bits/stdc++.h>
using namespace std;

struct Item{
	int weight;
	int val;
};

struct comparator{
	bool operator()(Item first, Item second){
		return (double)first.val/first.weight < (double)second.val/second.weight;	
	}
}; 


double fractionalKnapSack(vector<Item>&ItemsArr, int capacity){
	priority_queue<Item, vector<Item>, comparator>pq;
	double maxValue = 0;
	for(auto item : ItemsArr){
		pq.push(item);
	}

	while(capacity && !pq.empty()){
		auto topItem = pq.top();
		pq.pop();
		if(topItem.weight <= capacity){
			maxValue += topItem.val;
			capacity -= topItem.weight;
		}
		else{
			maxValue += (double)(topItem.val/topItem.weight)*capacity;
			capacity = 0;
		}
	}
	return maxValue;
}


int main(){
	int totalItems, capacity;
	cout << "Total items : ";
	cin >> totalItems;
	cout << "Capacity : ";
	cin >> capacity;
	vector<Item>ItemsArr(totalItems);
	for(int index = 0; index < totalItems; ++index){
		int val, weight;
		cout << "Value : ";
		cin >> val;
		cout << "weight : ";
		cin >> weight;
		ItemsArr[index].val = val;
		ItemsArr[index].weight = weight; 
	}
	cout << fractionalKnapSack(ItemsArr, capacity) << endl;
	return 0;
}