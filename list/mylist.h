#include <cstdlib>
#include "mylistnode.h"

template <typename T> class List{

private:
    int _size;
    ListNodePosi(T) header;
    ListNodePosi(T) trailer;

protected:
    void init();
    int clear();
    void copyNodes( ListNodePosi(T), int );
    void merge( ListNodePosi(T)&, int, List<T>&, ListNodePosi(T)&, int);
    void mergeSort(ListNodePosi(T)&, int);
    void selectionSort(ListNodePosi(T), int);
    void insertionSort(ListNodePosi(T), int);

public:
    //构造函数
    List(){ init(); }
    List( List<T> const& L);
    List( List<T> const& L, Rank r, int n);
    List( ListNodePosi(T) p, int n);
    //析构函数
    ~List();
    //只读接口
    Rank size() const { return _size; }
    bool empty() const { return _size <= 0; }
    T& operator[]( Rank r) const;
    bool valid(ListNodePosi(T) p){ return p && (trailer != p) && (header != p); }
    int disordered() const;
    ListNodePosi(T) first() const { return header->succ; }
    ListNodePosi(T) last() const { return trailer->pred; }
    ListNodePosi(T) find(T const& e, int n, ListNodePosi(T) p) const;
    ListNodePosi(T) find(T const& e) const{ return find(e, _size, trailer); }
    ListNodePosi(T) search(T const& e, int n, ListNodePosi(T) p) const;
    ListNodePosi(T) search(T const& e) const{ return search(e, _size, trailer); }
    ListNodePosi(T) selectMax(ListNodePosi(T) p, int n);
    ListNodePosi(T) selectMax(){ return selectMax(header->succ, trailer); }
    // 可写接口
    ListNodePosi(T) insertAsFirst( T const & e);
    ListNodePosi(T) insertAsLast( T const & e);
    ListNodePosi(T) insertA( ListNodePosi(T) p, T const& e);
    ListNodePosi(T) insertB( ListNodePosi(T) p, T const& e);
    T remove( ListNodePosi(T) p);
    void merge(List<T>& L){merge(first(), _size, L, L.first(), L._size); }
    void sort(ListNodePosi(T) p, int n);
    void sort(){ sort(first(), _size); }
    int deduplicate();
    int uniquify();
    void reverse();
    void printList();
};

template <typename T> void List<T>::init(){
    header = new ListNode<T>;
    trailer = new ListNode<T>;
    header->succ = trailer;
    header->pred = NULL;
    trailer->pred = header;
    trailer->succ = NULL;
    _size = 0;
}

template <typename T>
void List<T>::copyNodes(ListNodePosi(T) p, int n){
    init();
    while( n--){
        insertAsLast( p->data );
        p = p->succ;
    }
}

template <typename T>
int List<T>::clear(){
    int oldSize = _size;
    while( 0 < _size )
        remove( header->succ );
    return oldSize;
}

template < typename T>
List<T>::List ( ListNodePosi(T) p, int n){
    copyNodes(p, n);
}

template <typename T>
List<T>::List( List<T> const& L){
    copyNodes( L.first(), L._size );
}

template <typename T>
List<T>::List( List<T> const& L, int r, int n){
    copyNodes( L[r], n );
}

template <typename T>
List<T>::~List(){
    clear();
    delete header;
    delete trailer;
}

template <typename T>
T & List<T>::operator[]( Rank r) const{
    ListNodePosi(T) p = first();
    while( 0 < r-- )
        p = p->succ;
    return p->data;
}

template <typename T>
int List<T>::disordered() const{
    int n = 0;
    ListNodePosi(T) p = first();
    for( int i = 0; i < _size - 1; p = p->succ, i++)
        if(p->data > p->succ->data)
            n++;
    return n;
}
