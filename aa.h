#ifndef AA_H
#define AA_H

enum Color
{
    RED,
    BLACK
};

struct Node
{
    public:
        explicit Node(int value);
        int _value;
	int _level;
        Color rb;
        Node *left;
        Node *right;
};

class Tree
{
    public:
	//Add/Remove Functions as required
        Node *root;
        void insert(int value);
	void delet(int value);
	int find(int value);
        //void display(struct Node *head = root) const; //Wish this worked
	void display() const;	
	void inOrder(struct Node *head) const;
        Tree();
        explicit Tree(int value);
        explicit Tree(const Tree& rhs); //DOUBT: Why wasn't Copy Ctor made explicit in class?
        Tree operator=(const Tree& rhs);
        ~Tree();
};

#endif
