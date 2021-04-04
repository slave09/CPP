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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

		vector<vector<int>>result;

		queue<TreeNode*>queue;
		queue.push(root);

		int level = 0;

		while(!queue.empty()){

			int size = queue.size();
			vector<int>currLevel;

			for(int i = 0; i < size; ++i){

				TreeNode *node = queue.front();
				queue.pop();

				if(node){

					queue.push(node -> left);
					queue.push(node -> right);

					if(level % 2 == 0)
						currLevel.push_back(node -> val);
					else currLevel.insert(currLevel.begin(), node -> val);

				}
				
			}

			if(currLevel.size() != 0) result.push_back(currLevel);
			level++;        
		}
		return result;
	}
};


class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

		vector<vector<int>>zigzagTraversal;
		deque<TreeNode*>dq;
		dq.push_back(root);

		while(!dq.empty()){

			int number_of_nodes = dq.size();
			vector<int> level;

			for(int node = 0; node < number_of_nodes; ++node){

				if(zigzagTraversal.size() % 2){
					TreeNode * currNode = dq.front();
					dq.pop_front();
					if(currNode){
						dq.push_back(currNode -> right);
						dq.push_back(currNode -> left);
						level.push_back(currNode -> val);
					}
				}

				else{
					TreeNode * currNode = dq.back();
					dq.pop_back();
					if(currNode){
						dq.push_front(currNode -> left);
						dq.push_front(currNode -> right);
						level.push_back(currNode -> val);
					}
				}
			}

			if(level.size() != 0) 
				zigzagTraversal.push_back(level);
		}

		return zigzagTraversal;
	}
};
