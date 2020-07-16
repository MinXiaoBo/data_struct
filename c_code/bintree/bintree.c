#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bintree.h"

binTree initBinTree(int array[], int n){
    binTree T = NULL;
    for(int i = 0; i < n; i++){
        T = Insert(T, array[i]);
    }
    return T;
}

void destroyBinTree(binTree T){
    if(!T){
        return;
    }
    destroyBinTree(T->rc);
    destroyBinTree(T->lc);
    free(T);
}

binTree Insert(binTree T, dataType e){
    if(T == NULL){
        T = (binTree)malloc(sizeof(binNode));
        if(T == NULL)
            perror("malloc");
        else{
            T->data = e;
            T->rc = T->lc = NULL;
        }
    }else{
        if(e > T->data){
            T->rc = Insert(T->rc, e);
        }else
        if(e < T->data){
            T->lc = Insert(T->lc, e);
        }
    }
    return T;
}

bool empty(binTree T){
    return (T) ? true : false;
}

int size(binTree T){
    int s = 1;
    if(T->rc) s += size(T->rc);
    if(T->lc) s += size(T->lc);
    return s;
}

void travLevel(binTree T){
    if(!T) return;
}

void travPre(binTree T){
    if(!T) return;
    printf("%d ", T->data);
    travPre(T->lc);
    travPre(T->rc);
}

void travIn(binTree T){
    if(T){
        travIn(T->lc);
        printf("%d ", T->data);
        travIn(T->rc);
    }
}

void travPost(binTree T){
    if(!T) return;
    travPost(T->lc);
    travPost(T->rc);
    printf("%d ", T->data);
}

