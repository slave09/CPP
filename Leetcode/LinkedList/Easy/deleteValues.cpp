#include <iostream>
using namespace std;
// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// recursive solution

class Solution
{
public:
  ListNode *removeElements(ListNode *head, int val)
  {
    if (!head)
      return NULL;
    head->next = removeElements(head->next, val);
    return head->val == val ? head->next : head;
  }
};

// iterative solution

class Solution
{
public:
  ListNode *removeElements(ListNode *head, int val)
  {
    while (head && head->val == val)
      head = head->next;
    ListNode *present = head;
    while (present && present->next)
    {
      if (present->next->val == val)
        present->next = present->next->next;
      else
        present = present->next;
    }
    return head;
  }
};