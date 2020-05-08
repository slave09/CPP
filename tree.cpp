#include<iostream>
#include"queuecpp.h"

class tree{
public:
  Node * root;
  tree(){
    root = NULL;   
  }
  void createTree();
	void preorder(){preorder(root);}
  void preorder(Node * holder);
	void postorder(){postorder(root);}
  void Inorder(Node * holder);
	void Inorder(){Inorder(root);}
  void postorder(Node * holder);
  int treeHeight(Node *root);
};

void tree :: createTree(){
  Node *holder, *node;
	int value;
	QueueArray q(100);
	cout<<"Enter root value:";
	cin>>value;
	root = new Node;
	root->data = value;
	root->left_child = root->right_child = NULL;
	q.enqueue(root);

	while(! q.isEmpty()){
		holder = q.dequeue();
		cout<<"Enter left child of"<<holder->data<<":";
		cin>>value; 
		if( value != -1){
			node = new Node;
			node->data = value;
			node->left_child = node->right_child = NULL;
			holder->left_child = node;
			q.enqueue(node);
		}
		cout<<"Enter right child of"<< holder->data<<":";
		cin>>value; 
		if( value != -1){
			node = new Node;
			node->data = value;
			node->left_child = node->right_child = NULL;
			holder->right_child = node;
			q.enqueue(node);
		}
	}
}

void tree :: preorder(struct Node *holder){
	if(holder){
		cout<<holder->data<<" " ;
		preorder(holder->left_child);
		preorder(holder->right_child);
	}
}

void tree :: postorder(struct Node *holder){
	if(holder){
		postorder(holder->left_child);
		postorder(holder->right_child);
		cout<<holder->data<<" " ;
		}
}

void tree :: Inorder(struct Node *holder){
	if(holder){
		postorder(holder->left_child);
		cout<<holder->data<<" " ;
		postorder(holder->right_child);
	}
}

int tree :: treeHeight(Node *root){
  int leftChild, rightChild;
  leftChild = rightChild = 0;
  if(root == 0)
    return 0;
  leftChild  = treeHeight(root->left_child);
  rightChild  = treeHeight(root->right_child);
  if(leftChild > rightChild)
    return leftChild +1;
  else
    return rightChild + 1;
}

int main(){
  tree t;
  t.createTree();
  cout<<"Height of tree :"<<t.treeHeight(t.root)<<endl;
	cout<<"inorder"<<endl;
	t.Inorder();
	cout<<endl<<"preorder"<<endl;
	t.preorder();
	cout<<endl<<"postorder"<<endl;
	t.postorder();
	return 0;
}