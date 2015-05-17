#include <iostream>
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
    newTree.lookup(i);
    
    std::cout << "inserting 4" << "\n" ;
    i = 4;
    newTree.lookup(i);

    std::cout << "inserting 2" << "\n" ;
    i = 2;
    newTree.lookup(i);


    std::cout << "inserting 7" << "\n" ;
    i = 7;
    newTree.lookup(i);

    std::cout << "inserting 10" << "\n" ;
    i = 10;
    newTree.lookup(i);

    std::cout << "inserting 8" << "\n" ;
    i = 8;
    newTree.lookup(i);
    
 	
	std::cout << "printing ..." << "\n" ;
    newTree.print(newTree.root);
    
    
    return 0;
}
