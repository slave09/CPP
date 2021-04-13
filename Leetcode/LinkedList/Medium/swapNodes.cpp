/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {

        if(!head || !head -> next ) return head;

        vector<int> nodeVal;
        ListNode *root = head;
        
        while(root){
            nodeVal.push_back(root -> val);
            root = root -> next;
        }
        
        int size = nodeVal.size();
        swap(nodeVal[k-1], nodeVal[size - k]);
        
        ListNode *list = new ListNode(0);
        root = list;
        
        for(auto node : nodeVal){
            root -> next = new ListNode(node);
            root = root -> next;
        }
        
        return list -> next;
        
    }
};