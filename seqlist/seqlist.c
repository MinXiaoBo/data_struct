#include "seqlist.h"

#define swap(a,b) (a^=b,b^=a,a^=b)
#define max(a,b) (a > b) ? a : b

#define DEFAULT_CAPACITY 50


int initList(List L){
    L->_elem = (dataType *)malloc(sizeof(dataType)*DEFAULT_CAPACITY);
    if(L->_elem == NULL){
        printf("init failed!");
        return -1;
    }
    L->_size = 0;
    L->_capacity = DEFAULT_CAPACITY;
    return 0;
}

int destoryList(List L){
    if(L->_elem != NULL){
        free(L->_elem);
    }
    L->_size = 0;
    return 0;
}

int expend(List L){
    if(L->_size  < L->_capacity)
        return -1;
    L->_capacity = max(L->_capacity, DEFAULT_CAPACITY);
    L->_elem = (dataType *)realloc(L->_elem, sizeof(dataType)*(L->_capacity <<= 1));
    if(!L->_elem){
        printf("expend failed!\n");
        return -1;
    }
    return 0;
}

int shrink(List L){
    if(L->_capacity < DEFAULT_CAPACITY << 1)
        return -1;
    if(L->_size <<2 > L->_capacity)
        return -1;
    L->_elem = (dataType *)realloc(L->_elem, sizeof(dataType)*(L->_capacity >>= 1));
    if(!L->_elem){
        printf("shrink failed!\n");
        return -1;
    }
    return 0;
}

bool empty(List L){
    return !(L->_size);
}

int size(List L){
    return L->_size;
}

int disordered(List L){
    int count = 0;
    for(int i = 0; i < L->_size; i++){
        if(L->_elem[i] > L->_elem[i+1]){
            count++;
        }
    }
    return count;
}

pos insertElem(List L, dataType e, pos p){
    expend(L);
    for(int i = L->_size; i > p; i--){
        L->_elem[i+1] = L->_elem[i];
    }
    L->_elem[p] = e;
    L->_size++;
    return p;
}

dataType removeElem(List L, pos p){
    shrink(L);
    dataType temp = L->_elem[p];
    for(int i = p; i < L->_size; i++){
        L->_elem[i] = L->_elem[i+1];
    }
    L->_size--;
    return temp;
}

bool bubble(List L){
    pos lo = 0;
    pos hi = L->_size;
    bool sorted = true;
    while(++lo < hi){
        if(L->_elem[lo-1] > L->_elem[lo]){
            swap(L->_elem[lo-1], L->_elem[lo]);
            sorted = false;
        }
    }
    return sorted;
}

void bubbleSort(List L){
    while(!bubble(L));
}

pos findElem(List L, dataType e){
    pos lo = 0;
    pos hi = L->_size;
    while(lo < hi-- && e != L->_elem[hi]);
    return hi;
}

pos binSearch(List L, dataType e){
    pos lo = 0;
    pos hi = L->_size;
    while(lo < hi){
        pos mi = (lo + hi) >> 1;
        (e < L->_elem[mi]) ? (hi = mi) : (lo = mi+1);
    }
    return lo--;
}

void printSeqList(List L){
    printf("[ ");
    for(int i = 0; i < L->_size; i++){
        printf("%d ", L->_elem[i]);
    }
    printf("]\n");
}
