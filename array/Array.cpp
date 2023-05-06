#include "Array.h"
#include <iostream>


Array::Array(){
    n=0; 
    N=1;
    array = new int[N];
}


Array::~Array(){}


void Array::print(){
    for (int i=0; i<N; i++){
        if (i<n){
            std::cout<<array[i]<<" ";
        } else {
            std::cout<<"* ";
        }
    }
    std::cout<<"\n";
}


int Array::access(int i){
    return array[i];
}


void Array::push_back(int x){
    if (n==N) {
        N *= 2;
        resize(N);
    }
    array[n] = x;
    n++;
}


void Array::delete_(int x){
    /**
     * @brief deletes element x from array if it exists. To perform deletion, 
     * we swap x with the lastmost element of the array, then delete the back 
     * element. 
     * We perform resizing if the number of elements is < 1/4 length of the array
     */
    for (int i=0; i<n; i++){
        if (array[i] == x){
            int back = array[n-1];
            array[i] = back;
            array[n] = x;
            n--;
            break;
        }
    }

    // performs the resize
    if (n <= N/4.0) {
        N /=2 ;
        resize(N);
    }
}


int Array::search(int x){
    for (int i=0; i<n; i++) {
        if (array[i] == x) {
            return x;
        }
    }
    return 0; // just a dummy value
}


void Array::resize(int N){
    // resizes array to N
    int* new_array = new int[N];

    for (int i=0; i<n; i++) {
        new_array[i] = array[i];
    }
    
    delete[] array;
    array = new_array;
}