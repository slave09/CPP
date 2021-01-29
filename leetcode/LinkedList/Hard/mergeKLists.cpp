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

// T.L.E

class Solution {
    
    ListNode *merge(ListNode *l1, ListNode *l2){
        
        ListNode *merged_list = new ListNode();
        ListNode *res = merged_list;
        
        while(l1 && l2){
            
            if(l1 -> val > l2 -> val){
                res -> next = new ListNode(l2 -> val);
                res = res -> next;
                l2  = l2  -> next;
            }
            
            else{
                res -> next = new ListNode(l1 -> val);
                res = res -> next;
                l1  = l1  -> next;
            }
        }
        
        while(l1){res -> next = new ListNode(l1 -> val); res = res -> next; l1 = l1 -> next;}
        while(l2){res -> next = new ListNode(l2 -> val); res = res -> next; l2 = l2 -> next;}
        
        return merged_list -> next;
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        
        if(lists.size() == 1) return lists[0];
        
        ListNode *merged = lists[0];
        
        int index = 1;
        
        while(index < lists.size()){
            merged = merge(merged, lists[index++]);
        }

        return merged ;
        
    }
};