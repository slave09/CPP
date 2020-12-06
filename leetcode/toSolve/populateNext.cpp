/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    void connect_right(Node* root){
        if(root->next){
            if(root->next->left){
                if(root->left) root->left->next = root->next->left;
                else root->right->next = root->next->left; 
            }
        }
        else left ? root->left->next = NULL : root->right->next = NULL;
    }
public:
    Node* connect(Node* root) {
        if(root->left && root->right)
            root->left->next = root->right;
        if(root->left && !root->right) connect_right(root);
        if(root->right && !root->left) connect_right(root);
        connect(root->left);
        return root;
        }
    };