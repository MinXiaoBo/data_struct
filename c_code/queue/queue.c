#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef _Queue_H
#define _Queue_H

#define DEFAULT_CAPACITY 100

typedef int dataType;
typedef int Rank;

typedef struct{
    dataType * _elem;
    Rank _rear;
    Rank _front;
    Rank _size;
}Qnode;
typedef Qnode* Queue;

#endif


void intiQueue(Queue Q){
    Q = (Queue)malloc(sizeof(Qnode));
    if(!Q)
        exit(-1);
    Q->_elem = (dataType*)malloc(sizeof(dataType));
    if(!Q->_elem)
        exit(-1);
    Q->_size = 0;
    Q->_front = Q->_rear = 0;
}
