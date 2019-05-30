#include <iostream>
#include "fib.h"

using namespace std;

typedef int Rank;
#define _CAPACITY 10


template <class T> class Vector{
protected:
    T * _elem;
    Rank _size;
    int _capacity;

    void copyFrom(T const * array, Rank lo, Rank hi);
    void expend();
    void shrink();
    Rank bubble(Rank lo, Rank hi);
    void bubblesort(Rank lo, Rank hi);

public:
    Vector(int capa=_CAPACITY, Rank size=0, T data=0){ _elem = new T[_capacity=capa]; for(_size = 0; _size<size; _elem[_size++]=data);}
    Vector(T const * array, Rank n){ copyFrom(array, 0, n);}
    Vector(T const * array, Rank lo, Rank hi){ copyFrom(array, lo, hi); }
    Vector(Vector<T> const & V, Rank n){ copyFrom(V._elem, 0, n);}
    Vector(Vector<T> const & V, Rank lo, Rank hi){ copyFrom(V._elem, lo, hi);}

    //析构函数
    ~Vector(){ delete [] _elem; }

    //只读接口
    Rank size() const{ return _size; }
    bool empty() const{ return !_size; }
    Rank disordered() const;
    Rank find(T const & e, Rank lo, Rank hi)const ;
    Rank find(T const & e) const { return find(e, 0, _size); }
    Rank search(T const & e, Rank lo, Rank hi) const;
    Rank search(T const & e) const { return (0 >= _size) ? -1 : search(e, 0, _size); }
    void printVector() const;

    //可写接口
    T & operator[](Rank r) const{ return _elem[r]; }
    Vector<T> & operator=(Vector<T> const & V);
    Rank insert(Rank r, T const & e);
    Rank insert(T const & e){ return insert(_size, e); }
    T remove(Rank r);
    Rank remove(Rank lo, Rank hi);
    void sort(Rank lo, Rank hi);
    void sort(){ return sort(0, _size); }
};

template <class T>
Vector<T> & Vector<T>::operator=(Vector<T> const & V){
    if(_elem)
        delete [] _elem;
    copyFrom(V._elem, 0, _size);
    return * this;
}

template <class T>
void Vector<T>::copyFrom(T const * A, Rank lo, Rank hi){
    _elem = new T[_capacity=2*(hi-lo)];
    _size = 0;
    while(lo < hi){
        _elem[_size++] = A[lo++];
    }
}

template <class T>
void Vector<T>::expend(){
    if(_size < _capacity)
        return;
    if(_capacity < _CAPACITY)
        _capacity = _CAPACITY;
    T * oldElem = _elem;
    _elem = new T[_capacity <<= 1];
    for(int i = 0; i < _size; i++){
        _elem[i] = oldElem[i];
    }
    delete [] oldElem;
}

template <class T>
void Vector<T>::shrink(){
    if(_capacity < _CAPACITY << 1)
        return;
    if(_size << 2 > _capacity)
        return;

    T * oldElem = _elem;
    _elem = new T[_capacity << 1];
    for(int i = 0; i < _size; i++){
        _elem[i] = oldElem[i];
    }
    delete [] oldElem;
}

template <class T>
Rank Vector<T>::disordered() const{
    int count = 0;
    for(int i = 0; i < _size; i++){
        if(_elem[i] > _elem[i+1])
            count++;
    }
    return count;
}

template <class T>
Rank Vector<T>::insert(Rank r, T const & e){
    expend();
    for(int i = _size-1; i > r; i--){
        _elem[i+1] = _elem[i];
    }
    _elem[r] = e;
    _size++;
    return r;
}

template <class T>
Rank Vector<T>::remove(Rank lo, Rank hi){
    if(lo > hi)
        return 0;
    while(hi < _size)
        _elem[lo++] = _elem[hi++];
    _size = lo;
    shrink();
    return hi-lo;
}

template <class T>
T Vector<T>::remove(Rank r){
    T e = _elem[r];
    remove(r, r+1);
    return e;
}

template <class T>
Rank Vector<T>::find(T const & e, Rank lo, Rank hi) const{
    while(lo < hi-- && e != _elem[hi]);
    return hi;
}

template <class T>
Rank Vector<T>::bubble(Rank lo, Rank hi){
    int sorted = true;
    while(++lo < hi){
        if(_elem[lo-1] > _elem[lo]){
            sorted = false;
            swap(_elem[lo-1], _elem[lo]);
        }
    }
    return sorted;
}

template <class T>
void Vector<T>::bubblesort(Rank lo, Rank hi){
    while(! bubble(lo, hi));
}

template <class T>
void Vector<T>::sort(Rank lo, Rank hi){
    bubblesort(lo, hi);
}

template <class T>
static Rank binSearch(T * A, T const & e, Rank lo, Rank hi){
    while(lo < hi){
        Rank mi = (lo + hi) >> 1;
        (e < A[mi]) ? hi = mi : lo = mi + 1;
    }
    return --lo;
}

template <class T>
static Rank fibSearch(T * A, T const & e, Rank lo, Rank hi){
    Fib fib(hi - lo);
    while(lo < hi){
        while(hi - lo < fib.get())
            fib.prev();
        Rank mi = lo + fib.get() - 1;
        (e < A[mi]) ? hi = mi : lo = mi +1;
    }
    return --lo;
}

template <class T>
Rank Vector<T>::search(T const & e, Rank lo, Rank hi)const{

    return (rand() % 2) ? binSearch(_elem, e, lo, hi) : fibSearch(_elem, e, lo, hi);
}

template <class T>
void Vector<T>::printVector() const{
    cout << "[";
    for(int i = 0; i < _size; i++){
        cout << _elem[i] << " ";
    }
    cout << "]" << endl;
}
