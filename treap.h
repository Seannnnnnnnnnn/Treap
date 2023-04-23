struct Node
{
    int key;
    int priority;
    Node* left; 
    Node* right;
};



class Treap {
private:
    bool is_empty();
    Node* root;

public:
    Treap();
    ~Treap();

    void insert_node(int key);
    void delete_node(int key);
    void search(int key);

    Node* find(int key);
};


