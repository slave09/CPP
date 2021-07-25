#include<iostream>
using namespace std;
 // Definition for singly-linked list.
  struct ListNode {
      int val;
    ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode *reverse(ListNode * head){
      if(! head) return head;
      ListNode *last, *curr, *ahead;
      last = NULL, curr = head;
      while(curr){
        ahead = curr->next;
        curr->next = last;
        last = curr;
        curr = ahead;
      }
      return last;
    }

    ListNode * middleNode(ListNode * head){
      if(!head) return head;
      ListNode * slow,*fast;
      slow = fast = head;
      while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
      }
      return slow;
    }

    bool isPalindrome(ListNode* head) {
      if(!head) return true;
      ListNode *mid = middleNode(head);
      mid = mid->next = reverse(mid->next);
      while(mid){
        if(head->val != mid->val){
          return false;
        }
        mid = mid->next;
        head = head->next;
      }
      return true;
    }
};