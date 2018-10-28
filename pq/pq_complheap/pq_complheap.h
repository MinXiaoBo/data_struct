#include <iostream>
#include <cstdlib>
#include "../../vector/vector.h"
#include "../pq.h"

#define InHeap(n, i) (( (-1) < (i) ) && ( (i) < (n) ))
#define Parent(i) ( (i-1) >> 1 )
#define LastInternal(n) Parent( n-1 )
#define LChild(i) ( 1 + ( (i) << 1 ) )
#define RChild(i) ( ( 1 + (i) ) << 1 )
#define ParentValid(i) ( 0 < i )
#define LChildValid(n, i) InHeap(n, LChild(i) )
#define RChildValid(n, i) InHeap(n, RChild(i) )
#define Bigger(PQ, i, j) ( it( PQ[i], PQ[j] ) ? j : i )
#define  ProperParent(PQ, n, i) /*父子（至多）三者中的大者*/ \
            ( RChildValid(n, i) ? Bigger( PQ, Bigger( PQ, i, LChild(i) ), RChild(i) ) : \
            ( LChildValid(n, i) ? Bigger( PQ, i, LChild(i) ) : i \
            ) \
            ) //相等时父节点优先，如此可避免不必要的交换


template <typename T>
class PQ_ComplHeap:public PQ<T>, public Vector<T>{
protected:
    Rank percolateDown( Rank n, Rank i );  //下滤
    Rank percolateUp( Rank i ); //上滤
    void heapify( Rank n ); //Floyd建堆算法
public:
    PQ_ComplHeap(){}
    PQ_ComplHeap( T* A, Rank n ){ copyFrom( A, 0, n ); heapify( n ); }
    void insert( T );
    T getMax();
    T delMax();
};

template <typename T>
void PQ_ComplHeap<T>::insert( T e ){
    Vector<T>::insert( e );
    percolateUp( this->_size - 1 );
}

template <typename T>
T PQ_ComplHeap<T>::getMax(){
    return this->_elem[0];
}

template <typename T>
T PQ_ComplHeap<T>::delMax(){
    T maxElem = this->_elem[0];
    this->_elem[0] = this->_elem[--this->_size];
    percolateDown( this->_size, 0 );
    return maxElem;
}

template <typename T>
Rank PQ_ComplHeap<T>::percolateDown( Rank n, Rank i ){
    Rank j;
    while( i != ( j = ProperParent(this->_elem, n, i) )){
        swap(this-> _elem[i], this->_elem[j]);
        i = j;
    }
    return i;
}

template <typename T>
Rank PQ_ComplHeap<T>::percolateUp( Rank i ){
    while( ParentValid( i ) ){
        Rank j = Parent( i );
        if( it( this->_elem[i], this->_elem[j] ) ) break;
        swap( this->_elem[i], this->_elem[j] );
        i = j;
    }
    return i;
}

template <typename T>
void PQ_ComplHeap<T>::heapify( Rank n ){
    for( int i = LastInternal( n ); InHeap( n, i ); i--){
        percolateDown( n, i );
        for( int k = 0; k < n; k++){
            int kk = k;
            while( i < kk )
                kk = ( kk -1 )/2;
            i == kk ? print(this->_elem[k]) : printf("    ");
        }
        printf("\n");
    }
}
