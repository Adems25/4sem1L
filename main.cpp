#include "header.h"

int main()
{
    RBTree Tree;
    Tree.insert(6, 'G');
    Tree.insert(7, 'F');
    Tree.insert(8, 'H');
    Tree.insert(3, 'B');
    Tree.insert(5, 'A');
    Tree.insert(2, 'C');
    Tree.insert(4, 'E');
    Tree.insert(1, 'D');
    Tree.print();
    cout << "\nEND\n";
}