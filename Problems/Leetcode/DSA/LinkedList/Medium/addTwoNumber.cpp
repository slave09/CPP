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
	void addToLast(ListNode *node, int carry){
		while(node){
			node->val += carry;
			if(node->val > 9 && !node->next){
				cout << node->val ;
				node->val = node->val % 10;
				node->next = new ListNode();
			}
			else{
				if(node -> val < 10) carry = 0;
				else node -> val = node -> val % 10;
			}
			node = node->next;
		}
	}
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *one = l1, *two = l2;
		int carry = 0;
		while(one && two){
			int value = one->val + two->val + carry;
			if( value < 10)
			{				
				one->val = two->val = value;
				carry = 0; 
			}
			else
			{
				carry = 1;
				value %= 10;
				one->val = two->val = value;
				if(!one->next && !two->next){
					one->next = two->next = new ListNode(1);
					cout << one->next->val;
					return l1;
				}
			}
			one = one->next ;
			two = two->next;
		}
		if(! two && one ){
			addToLast(one,carry);
			return l1;
		} 
		else if(! one && two ){
			addToLast(two,carry);
			return l2;
		}	
		return l1;
	}
};