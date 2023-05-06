class Array
{
private:
    int N;
    int n;
    int* array;
    
    void resize(int N);
public:
    Array(/* args */);
    ~Array();

    void print();
    void push_back(int x);
    void delete_(int x);
    int  access(int i);
    int  search(int x);
};



