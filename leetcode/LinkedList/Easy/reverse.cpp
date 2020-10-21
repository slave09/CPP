#include<iostream>
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
  ListNode *reverseList(ListNode *head)
  {
    if (!head)
      return head;
    ListNode *ahead = head, *last = NULL;
    while (ahead)
    {
      ahead = ahead->next;
      head->next = last;
      last = head;
      head = ahead;
    }
    return last;
  }
};