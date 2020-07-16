#include <stdbool.h>

#ifndef _BINTREE_H
#define _BINTREE_H

typedef int dataType;

typedef struct node{
    dataType data;
    struct node * rc;
    struct node * lc;
}binNode, * binTree;

binTree initBinTree(int array[], int n);
void destroyBinTree(binTree T);
bool empty(binTree T);
int size(binTree T);
binTree Insert(binTree T, dataType e);
void travLevel(binTree T);
void travPre(binTree T);
void travIn(binTree T);
void travPost(binTree T);

#endif
