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
	bool isMirror(TreeNode *l, TreeNode *r){
		if(!l && !r) return true;
		if(!l || !r) return false;
		return l->val == r->val && isMirror(l->left, r->right) && isMirror(l->right,r->left);
	}
public:
	bool isSymmetric(TreeNode* root){
		if(!root) return true;
		return isMirror(root->left,root->right);
	}
};

class Solution2 {
public:
	bool isSymmetric(TreeNode* root){
		queue<TreeNode *>q;
		q.push(root) ;
		q.push(root) ;
		while(!q.empty()){
			ListNode *left = q.front();
			q.pop();
			ListNode *right = q.front();
			q.pop();
			if(!left && !right) continue;
			if(!left || !right) return false;
			if(left->val != right->val ) return false;
			q.push(left->left);
			q.push(right->right);
			q.push(left->right);
			q.push(right->left);
		}
	}
};