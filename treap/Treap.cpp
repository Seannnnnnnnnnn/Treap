#include "Treap.h"


/**
 * Private Methods: 
 */
Node* Treap::rotate_left(Node* x){
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

Node* Treap::rotate_right(Node* x){
    Node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}


Node* Treap::insert_util(Node* root, int key){
    if (root==nullptr) {
        return new Node(key);
    } 
    
    if (key < root->key) {
        root->left = insert_util(root->left, key);

        // rebalance if necessary:
        if (root->left->priority > root->priority) {
            root = rotate_right(root);
        }

    } else if (key > root->key) {
        root->right = insert_util(root->right, key);

        // rebalance if necessary:
        if (root->right->priority > root->priority) {
            root = rotate_left(root);
        }
    }
    
    return root;
}


Node* Treap::search_util(Node* root, int key){
    if (root == nullptr || root->key == key){
        return root;
    } 

    if (key < root->key){
        return search_util(root->left, key);
    }
    
    return search_util(root->right, key);
}

/**
 * Public Methods: 
 */
Treap::Treap(){
    n = 0;
    root = nullptr;
    srand(time(nullptr));    // set random seed
}

Treap::~Treap(){}

void Treap::insert(int x){
    n++;
    root = insert_util(root, x);
}


void Treap::delete_(int x){
    n--;
    Node* node = search(x);
}


Node* Treap::search(int key){
    return search_util(root, key);
}


void Treap::contains(int key){
    Node* node = search(key);

    if (node == nullptr){
        std::cout<< key << " not contained in Treap\n";
    } else {
        std::cout<< key << "  contained in Treap\n";
    }
}