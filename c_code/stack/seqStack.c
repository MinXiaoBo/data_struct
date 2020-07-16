#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEFAULT_CAPACITY 100

typedef int dataType;
typedef int Rank;

typedef struct{
    dataType *_elem;
    Rank _top;
}stackNode;

typedef stackNode * stack;

stack initStack(){
    stack S = (stack)malloc(sizeof(stackNode));
    if(!S)
        return NULL;
    S->_elem = (dataType *)malloc(sizeof(dataType)*DEFAULT_CAPACITY);
    S->_top = -1;
    return S;
}

void destroyStack(stack S){
    if(!S)
        return;
    if(!S->_elem)
        return;
    free(S->_elem);
    S->_top = -1;
}

bool empty(stack S){
    return (S->_top == -1);
}

void pop(stack S){
    if(empty(S))
        return;
    S->_top--;
}

void push(stack S, dataType e){
    S->_elem[++S->_top] = e;
}

dataType top(stack S){
    if(empty(S)){
        printf("top error. empty stack!\n");
        return 0;
    }
    return S->_elem[S->_top];
}

void makeEmpty(stack S){
    if(empty(S))
        return;
    S->_top = -1;
}


int main(int argc, char * argv[]){
    stack S = initStack();
    for(int i = 0; i < 10; i++){
        push(S, i);
    }
    printf("empty: %s\n", (empty(S)) ? "true" : "false");
    for(int i = 0; i < 10; i++){
        printf("top: %d\n", top(S));
        pop(S);
    }
    makeEmpty(S);
    printf("empty: %s\n", (empty(S)) ? "true" : "false");
    for(int i = 0; i < 10; i++){
        push(S, i);
    }
    printf("empty: %s\n", (empty(S)) ? "true" : "false");
    return 0;
}
