#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node {
    int key, priority;
    Node *left, *right;

    Node(int key) {
        this->key = key;
        this->priority = rand();
        this->left = this->right = nullptr;
    }

    void print() {
        std::cout<< key;
    }
};

class Treap {
private:
    Node* root;

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        y->left = x;
        return y;
    }

    Node* rotateRight(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        y->right = x;
        return y;
    }

    Node* insertUtil(Node* root, int key) {
        if (root == nullptr) {
            return new Node(key);
        }

        if (key < root->key) {
            root->left = insertUtil(root->left, key);

            if (root->left->priority > root->priority) {
                root = rotateRight(root);
            }
        } else if (key > root->key) {
            root->right = insertUtil(root->right, key);

            if (root->right->priority > root->priority) {
                root = rotateLeft(root);
            }
        }

        return root;
    }

    Node* searchUtil(Node* root, int key) {
        if (root == nullptr || root->key == key) {
            return root;
        }

        if (key < root->key) {
            return searchUtil(root->left, key);
        }

        return searchUtil(root->right, key);
    }

public:
    Treap() {
        root = nullptr;
        srand(time(nullptr));
    }

    void insert(int key) {
        root = insertUtil(root, key);
    }

    Node* search(int key) {
        return searchUtil(root, key);
    }

    void contains(int key) {
        Node* node = search(key);
        if (node == nullptr) {
            std::cout<< key << " not contained in Treap\n";
        } else{
            std::cout<< key << " contained in Treap\n";
        }
    }
};

int main() {
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

    return 0;
}
