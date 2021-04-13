class Solution {
public:
	vector<int> sumZero(int n) {

		if(n == 1) return {0};

		vector<int>arr(n);

		if(n % 2 ){
			int mid = (n-1) / 2;
			arr[mid] = 0;
			for(int i = 0; i < mid; ++i){
				arr[i] = i + 1;
				arr[mid + i + 1] = (i + 1) * -1;
			}
		}

		else{
			int mid = (n-1)/2;
			for(int i = 0; i <= mid; ++i){
				arr[i] = i + 1;
				arr[mid + 1 + i] = -1 * (i + 1);
			}
		}

		return arr;
	}
}; 

class Solution {
public:
	vector<int> sumZero(int n) {

		if(n == 1) return {0};

		vector<int>arr(n);

		for(int i = 0; i < n; ++i){
			arr[i] = i * 2 - n + 1;
		}
		return arr;
	}
}; 