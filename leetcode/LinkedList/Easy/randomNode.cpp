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
	vector<int> v;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
	Solution(ListNode* head) {
		ListNode *curr = head;
		while(curr){
			v.push_back(curr->val);
			curr = curr->next;
		}
		
	}
	
    /** Returns a random node's value. */
	int getRandom() {
		int random_number = rand() % v.size();
		return v.at(random_number);
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */