#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
	string sequence(TreeNode *root){
		if(!root) return "";
		if(!root->left && !root->right) return to_string(root->val) + " ";
		return sequence(root->left) + sequence(root->right);
	}
public:
	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		return sequence(root2) == sequence(root1);
	}	
};