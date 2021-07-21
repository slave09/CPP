#include<iostream>
using namespace std;

void maximum_number_of_upvotes(){
	int review_type_array[3] = {0};
	int number_of_reviews;
	cin >> number_of_reviews;
	while(number_of_reviews--){
		int type_of_review;
		cin >> type_of_review;
		review_type_array[type_of_review - 1]++;
	}
	cout << review_type_array[0] + review_type_array[2] << endl;
}

int main(){
	int test_cases;
	cin >> test_cases;
	cout << "**************" << endl ;
	while(test_cases--)
		maximum_number_of_upvotes();
	return 0;
}