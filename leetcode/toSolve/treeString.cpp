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
	vector<string>v;
	string s = " ";
public:
	vector<string> binaryTreePaths(TreeNode* root) {
	  if(!root) return v;
	  if(! root->left && !root->right) {
	    s = s + to_string(root->val);
	    v.push_back(s);
	    return v;
    }
	  binaryTreePaths(root->left) ;
	  binaryTreePaths(root->right);
	  s = s + to_string(root->val) + "-" + ">" ;
	  return v;
	}
};
