#ifndef AA_H
#define AA_H

struct Node
{
    public:
        explicit Node(int value);
        explicit Node();
        int value;
	      int level;
        Node *left;
        Node *right;
        Node *parent;
        int count;
};

class Tree
{
    public:
      int lookup(int &);
      void skew(Node *);
      bool split(Node *);
      void rebal(Node *);
      Node *insert(Node *,Node *);
      void print(Node *);
      Tree()
      {
            root = NULL;
      }

	    //Add/Remove Functions as required
      Node *root;
      //void insert(int value);
	    void delet(int value);
	    int find(int value);
        //void display(struct Node *head = root) const; //Wish this worked
	    void display() const;	
	    void inOrder(struct Node *head) const;
      //Tree();
      explicit Tree(int value);
      explicit Tree(const Tree& rhs); //DOUBT: Why wasn't Copy Ctor made explicit in class?
      Tree operator=(const Tree& rhs);
      ~Tree();
};

#endif
