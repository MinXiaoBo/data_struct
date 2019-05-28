#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


#ifndef _Seqlist_h
#define _Seqlist_h

typedef int dataType;
typedef int pos;

struct seqList{
    int _capacity;
    int _size;
    dataType * _elem;
}mySeqList;

typedef struct seqList * List;


int initList(List L);
int destroyList(List L);
int expend(List L);
int shrink(List L);
bool empty(List L);
int size(List L);
int disordered(List L);
pos insertElem(List L, dataType e, pos p);
dataType removeElem(List L, pos p);
bool bubble(List L);
void bubbleSort(List L);
pos findElem(List L, dataType e);
pos binSearch(List L, dataType e);
//pos fibSearch(List L);
void printSeqList(List L);

#endif
