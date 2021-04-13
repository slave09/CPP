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
	int countNodes(TreeNode* root) {
		if(!root) return 0;
		queue<TreeNode *>q;
		int nodes_count = 0;
		q.push(root);
		while(! q.empty()){
			TreeNode *node = q.front();
			q.pop();
			if(!node) continue;
			else nodes_count ++;
			q.push(node -> left);
			q.push(node -> right);
		}
		
		return nodes_count;
	}
};