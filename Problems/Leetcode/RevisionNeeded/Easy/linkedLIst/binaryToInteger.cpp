// Convert Binary Number in a Linked List to Integer

// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
  int solve(ListNode *root, int val)
  {
    if (!root)
      return val;
    val = val * 2 + root->val;
    return solve(root->next, val);
  }

public:
  int getDecimalValue(ListNode *head)
  {
    if (!head)
      return 0;
    return solve(head, 0);
  }
};