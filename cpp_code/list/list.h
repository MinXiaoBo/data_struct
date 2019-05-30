#include <cstdlib>
#include "listnode.h"


template <typename T> class List {

private:
	int _size;
	ListNodePosi(T) header;
	ListNodePosi(T) trailer;

protected:
	void init();
	int clear();
	void copyNodes ( ListNodePosi(T), int );
    void merge(ListNodePosi(T)&, int, List<T>&, ListNodePosi(T)&, int);
    void mergeSort(ListNodePosi(T)&, int);
    void selectionSort(ListNodePosi(T), int);
    void insertionSort(ListNodePosi(T), int);

public:
    //构造函数
	List() { init(); }
	List ( List<T> const& L );
	List ( List<T> const& L, Rank r, int n );
	List ( ListNodePosi(T) p, int n );
    //析构函数
	~List();
    //只读接口
	Rank size() const { return _size; }
	bool empty() const { return _size <= 0; }
	T& operator[] ( Rank r ) const;
    bool valid(ListNodePosi(T) p){ return p && (trailer != p) && (header != p); }
    int disordered() const;
	ListNodePosi(T) first() const { return header->succ; }
	ListNodePosi(T) last() const { return trailer->pred; }
    ListNodePosi(T) find(T const& e, int n, ListNodePosi(T) p) const;
    ListNodePosi(T) find(T const& e) const{ return find(e, _size, trailer); }
    ListNodePosi(T) search(T const& e, int n, ListNodePosi(T) p) const;
    ListNodePosi(T) search(T const& e) const{ return search(e, _size, trailer); }
    ListNodePosi(T) selectMax(ListNodePosi(T) p, int n);
    ListNodePosi(T) selectMax(){ return selectMax(header->succ, _size); }
    //可写接口
	ListNodePosi(T) insertAsFirst ( T const& e );
	ListNodePosi(T) insertAsLast ( T const& e );
	ListNodePosi(T) insertA ( ListNodePosi(T) p, T const& e );
	ListNodePosi(T) insertB ( ListNodePosi(T) p, T const& e );
	T remove ( ListNodePosi(T) p );
    void merge(List<T>& L){ merge(first(), _size, L, L.first(), L._size); }
    void sort(ListNodePosi(T) p, int n);
    void sort(){ sort(first(), _size); }
    int deduplicate();
    int uniquify();
    void reverse();
    void PrintList();
};

template <typename T> void List<T>::init() {
	header = new ListNode<T>;
	trailer = new ListNode<T>;
	header->succ = trailer;
    header->pred = NULL;
	trailer->pred = header;
    trailer->succ = NULL;
	_size = 0;
}

template <typename T> //列表内部方法：复制列表中自位置p起的n项
void List<T>::copyNodes ( ListNodePosi(T) p, int n ) { //p合法，且至少有n-1个真后继节点
	init(); //创建头、尾哨兵节点并做初始化
	while ( n-- ) {
		insertAsLast ( p->data );
		p = p->succ;
	} //将起自p的n项依次作为末节点插入
}

template <typename T>
int List<T>::clear() {
	int oldSize = _size;
	while ( 0 < _size )
		remove ( header->succ );
	return oldSize;
}

template <typename T>
List<T>::List ( ListNodePosi(T) p, int n ) {
 	copyNodes ( p, n );
}

template <typename T>
List<T>::List ( List<T> const& L ) {
	copyNodes ( L.first(), L._size );
}

template <typename T>
List<T>::List ( List<T> const& L, int r, int n ) {
	copyNodes ( L[r], n );
}

template <typename T>
List<T>::~List(){
	clear();
	delete header;
	delete trailer;
}

template <typename T>
T& List<T>::operator[] ( Rank r ) const {
	ListNodePosi(T) p = first();
	while ( 0 < r-- )
		p = p->succ;
	return p->data;
}

template <typename T>
int List<T>::disordered() const{
    int n = 0;
    ListNodePosi(T) p = first();
    for(int i = 0; i < _size - 1; p = p->succ, i++)
        if(p->data > p->succ->data)
            n++;
    return n;
}

template <typename T>
void List<T>::merge(ListNodePosi(T)& p, int n, List<T>& L, ListNodePosi(T)& q, int m){
    ListNodePosi(T) pp = p->pred;
    while(0 < m){
        if((0 < n) && (p->data <= q->data)){
            if(q == (p = p->succ))
                break;
            n--;
        }else{
            insertB(p, L.remove((q = q->succ)->pred));
            m--;
        }
    }
}

template <typename T>
void List<T>::selectionSort(ListNodePosi(T) p, int n){
    ListNodePosi(T) head = p->pred;
    ListNodePosi(T) tail = p;
    for(int i = 0; i < n; i++)
        tail = tail->succ;
    while(1 < n){
        ListNodePosi(T) max = selectMax(head->succ, n);
        insertB(tail, remove(max));
        tail = tail->pred;
        n--;
    }
}

template <typename T>
void List<T>::insertionSort(ListNodePosi(T) p, int n){
    for(int r = 0; r < n; r++){
        insertA(search(p->data, r, p), p->data);
        p = p->succ;
        remove(p->pred);
    }
}

template <typename T>
ListNodePosi(T) List<T>::find(T const& e, int n, ListNodePosi(T) p)const{
    while(0 < n--)
        if(e == (p = p->pred)->data)
            return p;
    return NULL;
}

template <typename T>
ListNodePosi(T) List<T>::search(T const& e, int n, ListNodePosi(T) p)const{
    while(0 <= n--)
        if(((p = p->pred)->data) <= e)
            break;
    return p;
}

template <typename T>
ListNodePosi(T) List<T>::selectMax(ListNodePosi(T) p, int n){
    ListNodePosi(T) max = p;
    for(ListNodePosi(T) cur = p; 1 < n; n--)
        if(!lt((cur = cur->succ)->data, max->data))
            max = cur;
    return max;
}

template <typename T>
void List<T>::mergeSort(ListNodePosi(T)& p, int n){
    if(n < 2)
        return;
    int m = n >> 1;
    ListNodePosi(T) q = p;
    for(int i = 0;i < m;i++)
        q = q->succ;
    mergeSort(p , m);
    mergeSort(q, n - m);
    merge(p, m, *this, q, n-m);
}
template <typename T>
void List<T>::sort(ListNodePosi(T) p, int n){
    switch(rand() % 3){
        case 1:insertionSort(p, n);
               break;
        case 2:selectionSort(p ,n);
               break;
        default:mergeSort(p, n);
                break;
    }
}

template <typename T>
ListNodePosi(T) List<T>::insertAsFirst ( T const& e ){
	_size++;
	return header->insertAsSucc ( e );
} //e当作首节点插入

template <typename T>
ListNodePosi(T) List<T>::insertAsLast ( T const& e ){
	_size++;
	return trailer->insertAsPred ( e );
} //e当作末节点插入

template <typename T>
ListNodePosi(T) List<T>::insertA ( ListNodePosi(T) p, T const& e ){
	_size++;
	return p->insertAsSucc ( e );
} //e当作p的后继插入（After

template <typename T>
ListNodePosi(T) List<T>::insertB ( ListNodePosi(T) p, T const& e ){
	_size++;
	return p->insertAsPred ( e );
} //e当作p的前驱插入（Before

template <typename T>
T List<T>::remove ( ListNodePosi(T) p ){
    T e = p->data;
	p->pred->succ = p->succ;
	p->succ->pred = p->pred;
	delete p;
	_size--;
	return e;
}

template <typename T>
void List<T>::PrintList(){
    Rank Count = _size;
    ListNodePosi(T) p = header;
    while(Count--){
        p = p->succ;
        std::cout << p->data << " ";
    }
    std::cout << std::endl;
}
