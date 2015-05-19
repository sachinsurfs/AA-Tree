#include <iostream>


template<typename T>
class Tree
{

    private:
        struct Node
        {
            public:
                explicit Node(T value): _value(value),left(NULL),right(NULL),parent(NULL),level(1),count(1){};
                T _value;
                int level;
                Node *left;
                Node *right;
                Node *parent;
                int count;
        };
    public:
        /*Done*/
        void skew(Node *);
        bool split(Node *);
        void rebal(Node *);
        void insert(T value);
        void print(Node *) const;
        Node *root;
        Tree();
        explicit Tree(T value);
        /*Experimental*/
        void del(Node* root);
        void copy(const Node*);
        Tree(const Tree& rhs); //DOUBT: Why wasn't Copy Ctor made explicit in class? Ans : To pass const Tree as well.
        Tree operator=(const Tree& rhs);
        ~Tree();
        /*To be done*/
        void delet(T value);
        //int find(int value);
        //Iterator Class

        //Seperate out public and private
};



/*
 * Tree Constructors
 */
template<typename T>
Tree<T>::Tree():root(0){};

template<typename T>
Tree<T>::Tree(T value):root(new Node(value)){};

/*
 * Destructor
 */
    template<typename T>
Tree<T>::~Tree()
{
    del(root);
}

/*
 * Deleting Tree
 */
    template<typename T>
void Tree<T>::del(Tree::Node* root)
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
    template<typename T>
Tree<T>::Tree(const Tree& rhs):root(0)
{
    copy(rhs.root);
}

/*
 * Assignment Operator
 */
    template<typename T>
Tree<T> Tree<T>::operator=(const Tree& rhs)
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
    template<typename T>
void Tree<T>::copy(const Tree::Node* temp)
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
    template<typename T>
void Tree<T>::skew(Tree::Node *temp)
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
    template<typename T>
bool Tree<T>::split(Tree::Node *temp)
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
    template<typename T>
void Tree<T>::rebal(Tree::Node* temp)
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
    template<typename T>
void Tree<T>::insert(T value)
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
template<typename T>
void Tree<T>::print(Tree::Node* temp) const
{
    if (!temp)
        return;
    print(temp->left);
    std::cout <<"Value: "<<temp->_value << "  Count:" << temp->count;
    std::cout<<"  Level: "<<temp->level<< "\n";
    print(temp->right);
}


int main()
{

    //Tree t2();
    //Tree t(5);    
    //t.insert(3);
    //t.insert(7);
    //t.insert(1);
    //t.display();
    std::cout << "***********" << "\n" ;
    double i = 3.6;
    Tree<double> newTree;

    std::cout << "inserting 3" << "\n" ;
    newTree.insert(i);

    std::cout << "inserting 4" << "\n" ;
    i = 4;
    newTree.insert(i);

    std::cout << "inserting 2" << "\n" ;
    i = 2;
    newTree.insert(i);


    std::cout << "inserting 7" << "\n" ;
    i = 7;
    newTree.insert(i);

    std::cout << "inserting 10" << "\n" ;
    i = 10;
    newTree.insert(i);

    std::cout << "inserting 8" << "\n" ;
    i = 8;
    newTree.insert(i);


    std::cout << "printing ..." << "\n" ;
    newTree.print(newTree.root);

    std::cout << "Second tree" << "\n";
    Tree<double> new2(newTree);  
    new2.print(new2.root);

    std::cout << "Third tree" << "\n";
    Tree<double> new3(3);
    new3 = new2;
    new3.print(new3.root);

    return 0;
}



