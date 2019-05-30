#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#ifndef _SeqList_H
#define _SeqList_H

typedef int dataType;
typedef int Rank;

typedef struct{
    int _capacity;
    int _size;
    dataType * _elem;
}seqList;

typedef seqList * List;


int initList(List L);
int destroyList(List L);
int expend(List L);
int shrink(List L);
bool empty(List L);
Rank size(List L);
int disordered(List L);
Rank insertElem(List L, dataType e, Rank p);
dataType removeElem(List L, Rank p);
bool bubble(List L);
void bubbleSort(List L);
Rank findElem(List L, dataType e);
Rank binSearch(List L, dataType e);
void printSeqList(List L);

#endif

