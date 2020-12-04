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
    set<int>s;
    void inorder(TreeNode *root){
        if(!root) return;
        inorder(root->left);
        s.insert(root->val);
        inorder(root->right);
    }
public:
    int minDiffInBST(TreeNode* root) {
        if(!root) return 0;
        inorder(root);
        int last  = 0;
        int minim = INT_MAX;
        for (auto it = s.begin(); it != s.end(); ++it){
            minim = min(minim, *it - last);
            last = *it;
        } 
        return minim;
    }
};