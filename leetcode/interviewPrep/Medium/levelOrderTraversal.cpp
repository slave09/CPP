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
	vector<vector<int>> levelOrder(TreeNode* root) {
		
		if(!root) return {};
		
		queue<TreeNode *>queue;
		vector<vector<int>>levelOrderTraversal;
		queue.push(root);
		
		while(!queue.empty()){
			int size = queue.size();
			vector<int>currLevel;
			for(int i = 0; i < size; ++i){
				TreeNode *node = queue.front();
				queue.pop();
				if(node){
					queue.push(node -> left);
					queue.push(node -> right);
					currLevel.push_back(node -> val);
				}
			}
			if(currLevel.size() != 0)
				levelOrderTraversal.push_back(currLevel);
		}
		return levelOrderTraversal;
	}
};