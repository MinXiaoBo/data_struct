#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef _Queue_H
#define _Queue_H

#define DEFAULT_CAPACITY 50

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


Queue initQueue(){
    Queue Q = (Queue)malloc(sizeof(Qnode));
    if(!Q)
        exit(-1);
    Q->_elem = (dataType*)malloc(sizeof(dataType)*DEFAULT_CAPACITY);
    if(!Q->_elem)
        exit(-1);
    Q->_size = 0;
    Q->_front = Q->_rear = 0;
    return Q;
}

void destroyQueue(Queue Q){
    if(!Q)
        return;
    free(Q->_elem);
    Q->_size = Q->_front = Q->_rear = 0;
}

Rank size(Queue Q){
    return Q->_size;
}

bool empty(Queue Q){
    return !Q->_size;
}

void enqueue(Queue Q, dataType e){
    if(Q->_size >= DEFAULT_CAPACITY)
        return;
    Q->_elem[Q->_rear++] = e;
    Q->_size++;
}

dataType dequeue(Queue Q){
    if(empty(Q)){
        printf("queue empty!\n");
        return 0;
    }
    dataType e = Q->_elem[Q->_front++];
    Q->_size--;
    return e;
}

int main(int argc, char * argv[]){
    Queue Q = initQueue();
    printf("empty:%s\n", empty(Q)? "true" : "false");
    enqueue(Q, 10);
    printf("enqueue:%d\n", 10);
    enqueue(Q, 5);
    printf("enqueue:%d\n", 5);
    enqueue(Q, 3);
    printf("enqueue:%d\n", 3);
    enqueue(Q, 9);
    printf("enqueue:%d\n", 9);
    enqueue(Q, 8);
    printf("enqueue:%d\n", 8);
    printf("dequeue:%d\n", dequeue(Q));
    printf("dequeue:%d\n", dequeue(Q));
    enqueue(Q, 8);
    printf("enqueue:%d\n", 8);
    printf("dequeue:%d\n", dequeue(Q));
    printf("dequeue:%d\n", dequeue(Q));
    printf("dequeue:%d\n", dequeue(Q));
    printf("dequeue:%d\n", dequeue(Q));
    printf("dequeue:%d\n", dequeue(Q));
    printf("empty:%s\n", empty(Q)? "true" : "false");
    printf("size:%d\n", size(Q));
    return 0;
}
