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
        if(root->left && !root->left->next){
            if(root->next->left) root->left->next = root->next->left;
            else if(root->next->right) root->left->next = root->next->right;
        }
        else if(root->right && !root->right->next){
            if(root->next->left) root->right->next = root->next->left;
            else if(root->next->right) root->right->next = root->next->right;
        }
    }
public:
    Node* connect(Node* root) {
        if(!root) return root;
        Node* node = root;
        while(node){
            if(node->left && node->right) node->left->next = node->right;
            connect_right(node);
            node = node->left;
        }
        return root;
    }
};