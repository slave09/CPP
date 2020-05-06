#include<iostream>
#include"queuecpp.h"

class tree{
public:
  Node * root;
  tree(){
    root = NULL;   
  }
  void createTree();
  void preorder(Node * holder);
  void Inorder(Node * holder);
  void postorder(Node * holder);
  int treeHeight(Node *root);
};

void tree :: createTree(){
  Node *holder, *node;
	int value;
	QueueArray q(100);
	printf("Enter root value : ");
	scanf("%d", &value);
	root = new Node;
	root->data = value;
	root->left_child = root->right_child = NULL;
	q.enqueue(root);

	while(! q.isEmpty()){
		holder = q.dequeue();
		printf("Enter left child of %d : ", holder->data);
		scanf("%d", &value); 
		if( value != -1){
			node = new Node;
			node->data = value;
			node->left_child = node->right_child = NULL;
			holder->left_child = node;
			q.enqueue(node);
		}
		printf("Enter right child of %d : ", holder->data);
		scanf("%d", &value); 
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
		printf("%d ", holder->data);
		preorder(holder->left_child);
		preorder(holder->right_child);
	}
}

void tree :: postorder(struct Node *holder){
	if(holder){
		postorder(holder->left_child);
		postorder(holder->right_child);
		printf("%d ", holder->data);
		}
}

void tree :: Inorder(struct Node *holder){
	if(holder){
		postorder(holder->left_child);
		printf("%d ", holder->data);	
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
  cout<<t.treeHeight(t.root);
}