#ifndef _LIST_H
#define _LIST_H

#include <stdio.h>

typedef void List;
typedef int Rank;
typedef int DataType;

List * list_create(size_t n);
void list_destroy(List *L);
Rank list_insert(List *L, Rank R);
DataType list_remove(List *L, DataType e);
int shrink(List *L);
int expend(List *L);
bool empty(List *L);
int size(List *L);


#endif
