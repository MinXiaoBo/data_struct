#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#ifndef LinkList_H
#define LinkList_H

typedef int dataType;
typedef int Rank;

typedef struct node{
    dataType data;
    struct node * next;
}linkNode;

typedef linkNode * linkList;


linkList initList();
void destroyList(linkList header);
bool empty(linkList header);
Rank size(linkList header);
void append(linkList header, dataType e);
Rank insert(linkList header, dataType e, Rank r);
dataType removeByIndex(linkList header, Rank r);
Rank removeByData(linkList header, dataType e);
int removeAllByData(linkList header, dataType e);
void reverse(linkList header);
void reverse_R(linkList header);
linkList locNode(linkList header, dataType e);
linkList getNode(linkList header, Rank r);
void printList(linkList header);
void reversePrintList(linkList header);

#endif
