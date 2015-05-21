#ifndef AA_H
#define AA_H


class Tree
{
    /*Done*/
    struct Node
    {
        public:
            explicit Node(int value): _value(value),left(NULL),right(NULL),parent(NULL),level(1),count(1){};
            int _value;
            int level;
            Node *left;
            Node *right;
            Node *parent;
            int count;
    };

    Node* skew(Node *);
    Node* split(Node *);
    void rebal(Node *);
    void del(Node* root);
    void copy(const Node*);

    public:

    void insert(int val);
    void print(Node *) const;
    Node *root;
    Tree();
    explicit Tree(int value);
    /*Experimental*/

    Tree(const Tree& rhs); //DOUBT: Why wasn't Copy Ctor made explicit in class? Ans : To pass const Tree as well.
    Tree operator=(const Tree& rhs);
    ~Tree();
    friend ostream& operator<<(ostream& o, const Tree& t);
    /*To be done*/
    void delet(int value);
    //int find(int value);
    //Iterator Class
};

#endif
