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
	list<int> List;
public:
	void inorder(TreeNode *root){
		if(!root ) return ;
		inorder(root->left);
		List.push_back(root->val);
		inorder(root->right);
	}
	TreeNode* increasingBST(TreeNode *root){
		if(!root) return NULL;
		inorder(root);
		TreeNode *result = new TreeNode(0);
		TreeNode *ans = result;
		while(!List.empty()){
			result->right = new TreeNode(List.front());
			List.pop_front();
			result = result->right;
		}
		List.clear();
		return ans->right;
	}
};

class Solution2 {
	TreeNode *node;
public:
	void inorder(TreeNode *root){
		if(!root ) return ;
		inorder(root->left);
		node->right = root->val;
		node = node->left;
		inorder(root->right);
	}
	TreeNode* increasingBST(TreeNode *root){
		TreeNode *result = new TreeNode(0);
		node = result;
		return result->right;
	}
};