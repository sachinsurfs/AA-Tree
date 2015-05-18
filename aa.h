#ifndef AA_H
#define AA_H

struct Node
{
    public:
        explicit Node(int value);
        int _value;
        int level;
        Node *left;
        Node *right;
        Node *parent;
        int count;
};

class Tree
{
    public:
        /*Done*/
        void skew(Node *);
        bool split(Node *);
        void rebal(Node *);
        void insert(int val);
        void print(Node *) const;
        Node *root;
        Tree();
        explicit Tree(int value);
        /*Experimental*/
        void del(Node* root);
        void copy(const Node*);
	Tree(const Tree& rhs); //DOUBT: Why wasn't Copy Ctor made explicit in class? Ans : To pass const Tree as well.
        Tree operator=(const Tree& rhs);
        ~Tree();
        /*To be done*/
        void delet(int value);
        //int find(int value);
	//Iterator Class
};

#endif
