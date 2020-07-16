#include "seqlist.h"

#define random(x) (rand() % x)

int main(int argc, char * argv[]){
    seqList mySeqList;
    List L = &mySeqList;
    initList(L);

    dataType e = 0;

    for(int i = 0; i < 100; i++){
        e = (dataType)random(100);
        insertElem(L, e, i);
    }
    printSeqList(L);

    printf("empty: %s.\n", empty(L) ? "true" : "false");

    printf("list size is %d.\n", size(L));

    printf("disordered count is %d.\n", disordered(L));

    printf("the pos of %d is %d.\n", 5, findElem(L, 5));

    bubbleSort(L);

    printSeqList(L);

    removeElem(L, 5);

    printSeqList(L);

    removeElem(L, 1);

    printSeqList(L);

    printf("the pos of %d is %d.\n", 5, binSearch(L, 5));

    destroyList(L);

    printSeqList(L);

    return 0;
}
