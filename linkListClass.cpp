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
  LinkList(){head = NULL;}
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

/**
*gives the lenght of the link list
*@return the length of the linkList
*/

int LinkList :: getLength()
{
  Node * current = head;
  int nodes = 0;
  while(current != NULL)
  {
    nodes++;
    current = current->next;
  }
  return nodes;
}

void LinkList :: printList()
{
  Node * current = head;
  while(current)
  {
    cout<<current->data<<" ";
    current = current->next;
  }
  cout<<endl;
}

/**
*inserts the value in the list
*@param value to be inserted ,the position at which value is to be inserted
*/
void LinkList :: InsertValue(int value, int position)
{
  Node * insert = new Node;
  insert->data = value;
  if (position < 0 || position > getLength())
    return;
  else
  {
  Node * current = head ;
    if(position == 0){
      insert->next = head;
      head = insert;
    }
    else{
      for (int i = 0; i < position-1; ++i)
        current = current->next;
      insert->next = current->next;
      current->next = insert ;
    }
  }
}

/**
*removes the node of the given position 
*@param values from which linked list is to be created
*@return value have been deleted from list
*/

int LinkList :: removeValue(int position)
{
  Node * current = NULL, *prev_node;
  int removed = -1 ;
  if(position > getLength() || position < 0)
    return -1;
  if(position == 0)
  {
    prev_node = head;
    head = head->next;
    removed = prev_node->data;
    delete prev_node;
  }
  else{
    prev_node = head;
    for(int i = 0; i < position-1; i++){
    prev_node = prev_node->next;
    current = prev_node->next;     
    }
    prev_node->next = current->next;
    removed = current->data;
    delete current;
  }
  return removed;
}

int main()
{
  int values[] = {1, 2, 3, 4, 5};
  LinkList list(values, 5);
  cout<<"lenght of the list is " ""<<list.getLength();
  cout<<endl;
  list.printList();
  list.InsertValue(3, 2);
  cout<<"the new inserted LinkList: " "";
  list.printList();
  cout<<"removed Value is "<<list.removeValue(2)<<endl;
  cout<<"LinkList after removing inserted element: " "";
  list.printList();
  list.~LinkList();
  return 0;
}