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
        int last  = *s.begin();
        s.erase(s.begin());
        int minim = INT_MAX;
        for(auto i: s) cout << i << " ";
        for (auto it = s.begin(); it != s.end(); ++it){
            minim = min(minim, *it - last);
            last = *it;
        } 
        return minim;
    }
};

class Solution2 {
    int result = INT_MAX, last = -1;
public:
    int minDiffInBST(TreeNode* root) {
        if(root->left) minDiffInBST(root->left);
        if(last >= 0) result = min(result, root->val - last);
        last = root->val;
        if(root->right) minDiffInBST(root->right);
        return result;
    }
};