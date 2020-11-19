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
public:
	int RootToLeaf = 0;
	void preorder(TreeNode *root, int curr){
		if(root){
			curr = (curr << 1) | root->val;
			if(!root->left && !root->right) 
				RootToLeaf += curr;
			preorder(root->left, curr);
			preorder(root->right, curr);
		}
	}
  int sumRootToLeaf(TreeNode* root) {
  	preorder(root, 0);
  	return RootToLeaf;
  }
};					