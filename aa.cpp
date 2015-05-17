#include <iostream>
#include "aa.h"

Node::Node(int value):value(value),left(0),right(0),level(1){};
Node::Node():value(0),left(0),right(0),level(1){};

//Tree::Tree():root(0){};

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
        std::cout << head->value << "\n";
        inOrder(head->right);
    }
}

/*
 * Insert String into the Tree
 */
int Tree::lookup(int &value)
{
    Node *temp = new Node();
    temp->value = value;
    temp->level = 1;
    temp->count = 0;
    temp->left = NULL;
    temp->right = NULL;
    temp->parent = NULL;
    temp = insert(root, temp);
    return temp->count;
}
 
/*
 * Skew Tree
 */
 
void Tree::skew(Node *temp)
{
    Node *ptr = temp->left;
    if (temp->parent->left == temp)
        temp->parent->left = ptr;
    else
        temp->parent->right = ptr;
    ptr->parent = temp->parent;
    temp->parent = ptr;
    temp->left = ptr->right;
    if (temp->left != NULL)
      temp->left->parent = temp;
    ptr->right = temp;
    temp->level = (temp->left ? temp->left->level + 1 : 1);
}
 
/*
 * Splitting of AA Tree
 */
bool Tree::split(Node *temp)
{
    Node* ptr = temp->right;
    if (ptr && ptr->right && (ptr->right->level == temp->level))
    {
        if (temp->parent->left == temp)
            temp->parent->left = ptr;
        else
            temp->parent->right = ptr;
        ptr->parent = temp->parent;
        temp->parent = ptr;
        temp->right = ptr->left;
        if (temp->right != NULL)
            temp->right->parent = temp;
        ptr->left = temp;
        ptr->level = temp->level + 1;
        return true;
    }
    return false;
}
 
/*
 * Rebalancing of AA Tree
 */
void Tree::rebal(Node* temp)
{
    temp->left = NULL;
    temp->right = NULL;
    temp->level = 1;
    for (temp = temp->parent; temp != root; temp = temp->parent)
    {
        if (temp->level != (temp->left ? temp->left->level + 1 : 1 ))
        {
            skew(temp);
            if (temp->right == NULL)
                temp = temp->parent;
            else if (temp->level != temp->right->level)
                temp = temp->parent;
        }
        if (temp->parent != root)
        {
            if (split(temp->parent) == false)
                break;
        }
    }
}
 
/*
 * Insert Function to insert string into the tree
 */
Node* Tree::insert(Node* temp, Node* ins)
{
    if (root == NULL)
    {
        ins->count = 1;
        ins->parent = NULL;
        ins->left = NULL;
        ins->right = NULL;
        root = ins;
        return root;
    }
    if (ins->value < temp->value)
    {
        if (temp->left)
            return insert(temp->left, ins);
        temp->left = ins;
        ins->parent = temp;
        ins->count = 1;
        rebal(ins);
        return ins;
    }
    if (ins->value > temp->value)
    {
        if (temp->right)
            return insert(temp->right, ins);
        temp->right = ins;
        ins->parent = temp;
        ins->count = 1;
        rebal(ins);
        return ins;
    }
    temp->count++;
    delete ins;
    return temp;
}
 
/*
 * Display Tree Elements
 */
void Tree::print(Node* temp)
{
    if (!temp)
        return;
    print(temp->left);
    std::cout <<"Value: "<<temp->value << "  Count:" << temp->count;
    std::cout<<"  Level: "<<temp->level<< std::endl;
    print(temp->right);
}

