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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *tail = head;
		ListNode *nth = head;
		ListNode *last = head;
		n --;
		while(n--)
			last = last -> next;
		while(last && last->next){
			tail = nth;
			nth = nth -> next;
			last = last -> next;
		}
		if(nth == head) return head = head -> next;
		tail -> next = nth -> next;
		return head;
	}
};