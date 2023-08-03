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
	}
	long long rangeUpdateQuery(int node, int query_low, int query_high, int node_low, int node_high, int u){
		if(query_high < node_low || node_high < query_low) return 0;
		if(node_low	>= query_low && query_high >= node_high){ 
			if(u != -1) tree[node] += u;
			return tree[node];
		}
		int left_end_point = (node_low + node_high) / 2;
		long long sum = rangeUpdateQuery(2 * node, query_low, query_high, node_low, left_end_point,u)
		+ rangeUpdateQuery(2 * node + 1, query_low, query_high, left_end_point + 1, node_high,u);
		return sum + tree[node];
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
		int type;
		cin >> type;
		if(type == 1){
			int low, high, u;
			cin >> low >> high >> u;
			st.rangeUpdateQuery(1, low - 1, high - 1, 0, values - 1, u);
		}
		else{
			int k;
			cin >> k;
			cout << st.rangeUpdateQuery(1, k - 1, k - 1, 0, values - 1, -1) << endl;
		}
	}
	return 0;
}