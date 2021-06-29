#include<iostream>

int main() {
	int days;
	std :: cin >> days;
	if(days == 1){
		std :: cout << days << std :: endl;
		return 0;
	}
	int money, last = 0, length = 0, currLength = 0;

	while(days--){
		std :: cin >> money;
		if(last > money){ 
			length = std :: max(length, currLength);
			currLength = 1;
		}
		else currLength++;
		last = money;
	}
	currLength < length ? std :: cout << length : std :: cout << currLength;
	return 0;
}