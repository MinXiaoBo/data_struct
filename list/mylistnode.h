#include <iostream>

typedef int Rank;
#define ListNodePosi(T) ListNode<T>*

template <typename T> struct ListNode{
    T data;
    ListNodePosi(T) pred;
    ListNodePosi(T) succ;

    ListNode(){}
    ListNode(T e, ListNodePosi(T) p = NULL, ListNodePosi(T) s = NULL)
        : data(e), pred(p), succ(s){}
    ListNodePosi(T) insertAsPred(T const & e);
    ListNodePosi(T) insertAsSucc(T const & e);
};

template <typename T>
ListNodePosi(T) ListNode<T>::insertAsPred(T const & e){
    ListNodePosi(T) temp = new ListNode(e, pred, this);
    pred->succ = temp;
    pred = temp;
    return temp;
}

template <typename T>
ListNodePosi(T) ListNode<T>::insertAsSucc(T const & e){
    ListNodePosi(T) temp = new ListNode(e, this, succ);
    succ->pred = temp;
    succ = temp;
    return temp;
}
