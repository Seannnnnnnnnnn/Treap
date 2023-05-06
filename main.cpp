#include "array/Array.h"
#include "treap/Treap.h"
#include <iostream>


int main()
{
    Array array = Array();

    array.push_back(1);
    array.push_back(2);
    array.push_back(3);
    array.push_back(4);
    array.push_back(5);
    array.print();

    array.delete_(2);
    array.print();

    array.delete_(3);
    array.print();

    array.delete_(4);
    array.print();

    array.delete_(1);
    array.print();

    array.delete_(1);
    array.print();

    Treap treap;
    treap.insert(5);
    treap.insert(1);
    treap.insert(7);
    treap.insert(3);
    treap.insert(2);
    treap.insert(2);
    treap.insert(9);

    for (int i=0; i<10; i++){
        treap.contains(i);
    }
    
    std::cout<<"ciao\n";
}
