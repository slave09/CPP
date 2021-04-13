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
	bool isUnival(TreeNode* root, int last) {
		if(! root) return true;
		if(last != root->val) return false;
		return isUnival( root->left,root->val) && isUnival(root->right,root->val);
	}
public:
	bool isUnivalTree(TreeNode* root) {
		return isUnival(root,root->val);
	}

	bool isUnivalOtherSoln(TreeNode* root, int last = -1) {
		if(! root) return true;
		last = last == -1 ? root->val : last;
		if(last != root->val) return false;
		return isUnivalTree( root->left,root->val) && isUnivalTree(root->right,root->val);
	}
};