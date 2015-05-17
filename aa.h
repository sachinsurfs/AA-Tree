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
        /*To still be committed*/
        explicit Tree(const Tree& rhs); //DOUBT: Why wasn't Copy Ctor made explicit in class?
        Tree operator=(const Tree& rhs);
        ~Tree();
        void delet(int value);
        int find(int value);
};

#endif
