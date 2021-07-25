/**
 * Definition for a binary tree node->
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

	int morrisAlgorithm(TreeNode *root) {
		int rootToLeaf = 0, currNumber = 0;
		int steps;
		TreeNode *predecessor;

		while (root) {

    	// If there is a left child,
      // then compute the predecessor->
      // If there is no link predecessor->right = root --> set it->
      // If there is a link predecessor->right = root --> break it->

			if (root->left) {

      	// Predecessor node is one step to the left
      	// and then to the right till you can->

				predecessor = root->left;
				steps = 1;
				while(predecessor->right != null && predecessor->right != root){
					predecessor = predecessor->right;
					++steps;
				}

        // and go to explore the left subtree

				if (predecessor->right == null) {
					currNumber = (currNumber << 1) | root->val;
					predecessor->right = root;
					root = root->left;
				}
        
        // Break the link predecessor->right = root
        // Once the link is broken,
        // it's time to change subtree and go to the right
				
				else {
          
          // If you're on the leaf, update the sum
					
					if (!predecessor->left) rootToLeaf += currNumber;
          
          // This part of tree is explored, backtrack
					
					for(int i = 0; i < steps; ++i) currNumber >>= 1;
					
					predecessor->right = null;
					
					root = root->right;
				}
			}
      
      // If there is no left child
      // then just go right->
			
			else {
				currNumber = (currNumber << 1) | root->val;
        
        // if you're on the leaf, update the sum
				
				if (!root->right) rootToLeaf += currNumber;
				
				root = root->right;
			}

		}
		return rootToLeaf;
	}
};					