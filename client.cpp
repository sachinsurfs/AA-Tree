#include <iostream>
using std::ostream;
#include "aa.h"

using namespace std;
int main()
{

    //Tree t2();
    //Tree t(5);    
    //t.insert(3);
    //t.insert(7);
    //t.insert(1);
    //t.display();
    std::cout << "***********" << "\n" ;
    int i = 3;
    Tree newTree;

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
    Tree new2(newTree);  
    new2.print(new2.root);

    std::cout << "Third tree" << "\n";
    Tree new3(3);
    new3 = new2;
    new3.print(new3.root);

    return 0;
}
