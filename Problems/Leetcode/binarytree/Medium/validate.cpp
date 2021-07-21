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

    bool inorder(TreeNode *root, TreeNode *&last){
        if(!root) return true;
        if(!inorder(root -> left, last)) return false;
        if(last && last -> val >= root -> val) return false;
        last = root;
        return inorder(root -> right, last);
    }
public:
    bool isValidBST(TreeNode* root) {
        TreeNode *last = NULL;
        return inorder(root, last);
    }
};