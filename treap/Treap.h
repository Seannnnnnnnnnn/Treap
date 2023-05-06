#include <iostream>
#include <cstdlib>

#ifndef Node_H
#define Node_H


struct Node
{
    int key, priority;
    Node  *left, *right;

    Node(int key) {
        this->key = key;
        this->priority = std::rand();
        this->left = this->right = nullptr;
    }

    void print() {
        std::cout<<key<<std::endl;
    }
};


class Treap 
{
private:
    int n;
    Node* root;

    Node* rotate_left(Node* x);
    Node* rotate_right(Node* x);

    Node* insert_util(Node* root, int key);
    Node* search_util(Node* root, int key);

public:
    Treap();
    ~Treap();

    void  insert(int x);
    void  delete_(int x);
    Node* search(int key);

    void contains(int key);
};

#endif