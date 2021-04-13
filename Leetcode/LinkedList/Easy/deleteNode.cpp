using namespace std;

// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
  void deleteNode(ListNode *node)
  {
    ListNode *lead = node->next;
    node->val = lead->val;
    node->next = lead->next;
  }
};