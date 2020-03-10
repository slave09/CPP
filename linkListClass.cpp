#include<iostream>
using namespace std;
class Node
{
public:
  int data;
  Node *next;
};

class LinkList
{
private:
  Node * head; 
public:
  LinkList(){head = NULL};
  LinkList(int values[], int length);
  ~LinkList();

  void printList();
  int getLength();
  void InsertValue(int position, int value);
  int removeValue(int position);
};

LinkList :: LinkList(int values[], int length)
{
  Node *last,*current;
  head = new Node;
  head->data = values[0];
  last = head;
  for (int i = 1; i < length; i++)
  {
    current = new Node;
    current->data = values[i];
    current->next = NULL;
    last->next = current;
    last = current;
  } 
}

LinkList :: ~LinkList()
{
  Node *current= head;
  while(head)
  {
    head = head->next;
    delete current;
    current = head;
  }
}

int LinkList :: getLength()
{
  int nodes = 0;
  while(head)
  {
    nodes++;
    head = head->next;
  }
  return nodes;
}

void LinkList :: printList()
{
  while(head)
  {
    cout<<head->data<<" ";
    head = head->next;
  }
  cout<<endl;
}
void LinkList :: InsertValue(int value, int position)
{
  struct Node * node  = (struct Node *)malloc(sizeof(struct Node));
  node->data = value;
  if(position == 0)
  {
    node->next = head;
    head = node;
  }
  else
  {
    for (int i = 0; i < position-1; i++)
    {
      head = head->next;
      head->next = node;
      node->next = head->next;
    }
  }
}

int removeValue(int position)
{
  struct Node * node = NULL;
  if(position < 0 || position > getLength())
    return 0;
  else{
    for (int i = 0; i < position-1; i++)
    {
      head = head->next;
      node = head->next;
      head->next = node->next;
      int deleted = node->data;
      free (node);
    }
  }
  return deleted;
}

int main()
{
  int values[] = {1, 2, 3, 4, 5};
  LinkList list(values, 5);
  list.InsertValue(3, 9);
  list.printList();
  return 0;
}