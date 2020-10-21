#include<bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  ListNode *deleteDuplicates(ListNode *head)
  {
    if (!head)
      return head;
    ListNode *present = head;
    while (present)
    {
      if (present->next && present->val == present->next->val)
        present->next = present->next->next;
      else present = present->next;
    }
    return head;
  }
};
// recursive solution

class Solution
{
public:
  ListNode *deleteDuplicates(ListNode *head)
  {
    if (head == NULL || head->next == NULL)
      return head;
    head->next = deleteDuplicates(head->next);
    return head->val == head->next->val ? head->next : head;
  }
};