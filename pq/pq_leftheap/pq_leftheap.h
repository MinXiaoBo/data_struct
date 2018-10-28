#include <iostream>
#include <cstdlib>
#include "../pq.h"
#include "../../bintree/bintree.h"

template <typename T>
class PQ_LeftHeap : public PQ<T>, public BinTree<T>{
public:
    PQ_LeftHeap(){}
    PQ_LeftHeap( T* E, int n ){ for(int i = 0; i < n; i++) insert(E[i]); }
    void insert(T);
    T getMax();
    T delMax();
};

template <typename T>
void PQ_LeftHeap<T>::insert(T e){
    BinNodePosi(T) v = new BinNode<T>( e );
    this->_root = merge( this->_root, v );
    this->_size++;
}

template <typename T>
T PQ_LeftHeap<T>::getMax(){
    return this->_root->data;
}

template <typename T>
T PQ_LeftHeap<T>::delMax(){
    BinNodePosi(T) lHeap = this->_root->lc;
    BinNodePosi(T) rHeap = this->_root->rc;
    T e = this->_root->data;
    delete this->_root;
    this->_size--;
    this->_root = merge(lHeap, rHeap);
    return e;
}
