#include <iostream>
#include "aa.h"

Node::Node(int value):_value(value),left(0),right(0),rb(BLACK),_level(1){};

Tree::Tree():root(0){};

Tree::Tree(int value):root(new Node(value)){};

Tree::~Tree(){};

#if 0
//Simple BST
void Tree::insert(int value)
{
    if(root == NULL)
        root = new Node(value);
    else
    {
	struct Node *prev,*curr;
	prev = 0;
	curr = root;
        while(curr != NULL)
      	{
          prev=curr;
          if(value < curr->_value)
            curr=curr->left;
           else
            curr=curr->right;
      	}
      if(value < prev->_value)
        prev->left= new Node(value);
      else
        prev->right= new Node(value);
      }
}
#endif

void Tree::display() const
{
    inOrder(root);
}

void Tree::inOrder(struct Node *head) const
{
    if(head != NULL)
    {
        inOrder(head->left);
        std::cout << head->_value << "\n";
        inOrder(head->right);
    }
}
