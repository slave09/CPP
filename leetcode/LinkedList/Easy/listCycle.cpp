/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
      ListNode *fast = head, *slow = head;
      while(fast && slow){
        fast = fast->next;
        fast = fast ? fast->next : fast;
        slow = slow->next;
        if(fast && fast == slow) return true;
      }
      return false;
    }
};