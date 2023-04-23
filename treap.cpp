#include "treap.h"
#include <stdlib.h>

void Treap::insert_node(int key){
    // insert node with key into the Treap
    
    Node *node = new Node;
    node->key = key;
    node->priority = rand();

    if (root == NULL) {
        root = node;
    }
}