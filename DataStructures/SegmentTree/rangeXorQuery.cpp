#include<bits/stdc++.h>
using namespace std;

class segmentTreeCLass{
	vector<long long>tree;
public:
	segmentTreeCLass(vector<int>&nums){
		tree.resize(nums.size() * 2);
		for(int index = 0; index < nums.size(); ++index){
			tree[nums.size() + index] = nums[index];
		}
		for(int index = nums.size() - 1; index >= 1; index--){
			tree[index] = tree[2 * index] ^ tree[2 * index + 1];
		}
	}

	int rangeXORQuery(int node, int query_low, int query_high, int node_low, int node_high){
		if(query_high < node_low || node_high < query_low) return 0;
		if(node_low	>= query_low && query_high >= node_high) return tree[node];
		int left_end_point = (node_low + node_high) / 2;
		int right_start_point = left_end_point + 1;
		return rangeXORQuery(2 * node, query_low, query_high, node_low, left_end_point) ^ rangeXORQuery(2 * node + 1, query_low, query_high, right_start_point, node_high);
	}

	void update(int k, int u, int n){
		tree[n + k] = u;
		for(int i = (k + n) / 2; i >= 1; i /= 2){
			tree[i] = tree[i * 2] ^ tree[i * 2 + 1];
		}
	}
};

int main(){
	int values, queries;
	cin >> values >> queries;
	vector<int>valArr(values);
	for(int index = 0; index < values; ++index){
		cin >> valArr[index];
	}
	while(__builtin_popcount(values) != 1){
		valArr.push_back(0);
		values++;
	}
	segmentTreeCLass st(valArr);
	while(queries--){
			int low, high;
			cin >> low >> high;
			cout << st.rangeXORQuery(1, low - 1, high - 1, 0, values - 1) << endl;
	}
	return 0;
}