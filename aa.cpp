#include <iostream>
#include "aa.h"


/*
 * Node Constructor
 */

Node::Node(int value):_value(value),left(NULL),right(NULL),parent(NULL),level(1),count(1){};

/*
 * Tree Constructors
 */

Tree::Tree():root(0){};

Tree::Tree(int value):root(new Node(value)){};

/*
 * Destructor
 */

Tree::~Tree()
{
    del(root);
}

/*
 * Deleting Tree
 */

void Tree::del(Node* root)
{
    Node *temp = root;

    if(root == NULL)
        return;
    if(root->left == NULL && root->right == NULL)
    {		delete root;
        return;
    }
    if(root->left)
    {
        del(root->left);
    }

    if(root->right)
    {
        del(root->right);
    }

    delete root;
    return;

}


/*
 * Copy Constructor
 */

Tree::Tree(const Tree& rhs):root(0)
{
    copy(rhs.root);
}

/*
 * Assignment Operator
 */
Tree Tree::operator=(const Tree& rhs)
{

    if(this != &rhs)
    {
        del(root);
        copy(rhs.root);
    }
    return *this;
}

/*
 * Tree Copy Function
 */
void Tree::copy(const Node* temp)
{
    if (temp)
    {
        insert(temp->_value);
        copy(temp->left);
        copy(temp->right);
    }
    return;
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
 * Insert Function to insert into the tree
 */
void Tree::insert(int value)
{
    if (root == NULL)
        root = new Node(value);
    else 
    {
        struct Node *temp = root, *prev = 0;
        while(temp != NULL)
        {
            prev = temp;
            if (value < temp->_value)
                temp = temp->left;
            else if (value > temp->_value)
                temp = temp->right;
            else
            {
                temp->count++;
                return;
            }
        }
        if(value < prev->_value)
        {	prev->left = new Node(value);
            prev->left->parent = prev;
            rebal(prev->left);
        }  else
        {
            prev->right= new Node(value);
            prev->right->parent = prev;
            rebal(prev->right);
        }

    }

}

/*
 * Display Tree Elements
 */
void Tree::print(Node* temp) const
{
    if (!temp)
        return;
    print(temp->left);
    std::cout <<"Value: "<<temp->_value << "  Count:" << temp->count;
    std::cout<<"  Level: "<<temp->level<< "\n";
    print(temp->right);
}

