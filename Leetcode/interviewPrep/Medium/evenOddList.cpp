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
    
    ListNode *removeNext(ListNode *head){
        
        if(!head || !head -> next) return NULL;
        
        ListNode *next = head -> next;
        head -> next = next -> next;
        delete next;
        return head;
    }
    
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head -> next) return head;
        
        ListNode *list = new ListNode();
        ListNode * node = list;
        ListNode * currNode = head;
        
        while(currNode && currNode -> next){
            node -> next = new ListNode(currNode -> next -> val);
            currNode = removeNext(currNode);
            node = node -> next;
            currNode = currNode -> next;
        }
        
        node = head;
        
        while(node -> next) node = node -> next;
        
        node -> next = list -> next;
        
        return head;
        
    }
};