#include <iostream>
using std::ostream;
#include "aa.h"

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

void Tree::del(Tree::Node* root)
{
    if(root == NULL)
        return;
    del(root->left);
    del(root->right);
    delete root;

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
void Tree::copy(const Tree::Node* temp)
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

Tree::Node* Tree::skew(Tree::Node *temp)
{
    if (temp->left != NULL)
        if (temp->left->level == temp->level)   
        { 
            Node *ptr = temp->left;
            temp->left = ptr->right;
            if(ptr->right != NULL)
                ptr->right->parent = temp;

            ptr->right = temp;
            ptr->parent = temp->parent;
            temp->parent = ptr;
            return ptr;
        }
    return temp;
}

/*
 * Splitting of AA Tree
 */
Tree::Node* Tree::split(Tree::Node *temp)
{
    if(temp->right!=NULL && temp->right->right!=NULL)
        if(temp->level == temp->right->right->level)
        {
            Node *ptr = temp->right;
            temp->right = ptr->left;
            if(ptr->left != NULL)
                ptr->left->parent = temp;
            ptr->left = temp;
            ptr->parent = temp->parent;
            temp->parent = ptr;
            if(ptr->parent != NULL)
                ptr->parent->right = ptr;
            ptr->level = ptr->level + 1;
            return ptr;
        }
    return temp;

}    


/*
 * Rebalancing of AA Tree
 */
void Tree::rebal(Tree::Node* temp)
{
    while(temp->parent != NULL)
    {
        temp = temp->parent;
        if(temp == root)
        {
            temp = skew(temp);
            temp = split(temp);
            root = temp;
        }
        else
        {
            temp = skew(temp);
            temp = split(temp);
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
void Tree::print(Tree::Node* temp) const
{
    if (!temp)
        return;
    print(temp->left);
    std::cout <<"Value: "<<temp->_value << "  Count:" << temp->count;
    std::cout<<"  Level: "<<temp->level<< "\n";
    print(temp->right);
}

/*
 * Send Tree To output stream
 */
ostream& operator<<(ostream& o, const Tree& t)
{



}



