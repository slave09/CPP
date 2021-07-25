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

class Solution
{
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
  {
    ListNode head(INT_MIN);
    ListNode *Newlist = &head;
    while (l1 && l2)
    {
      if (l1->val < l2->val)
      {
        Newlist->next = l1;
        l1 = l1->next;
      }
      else
      {
        Newlist->next = l2;
        l2 = l2->next;
      }
      Newlist = Newlist->next;
    }
    Newlist->next = l1 ? l1 : l2;
    return head.next;
  }
};