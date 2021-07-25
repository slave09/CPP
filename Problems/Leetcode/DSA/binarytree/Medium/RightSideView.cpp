#include<bits/stdc++.h>
using namespace std;

class Solution {
	vector<int>res;
	void RightView(TreeNode *root, int depth){
		if(!root)return;

		if(depth == res.size()) res.push_back(root -> val);

		RightView(root -> right, depth + 1);
		RightView(root -> left, depth + 1);
	}
	public:
		vector<int> rightSideView(TreeNode *root){
			if(!root) return {};

			RightView(root, 0);

			return res;
		}
};
