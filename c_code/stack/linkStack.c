#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int dataType;
typedef int Rank;

typedef struct node{
    dataType data;
    struct node * next;
}stackNode;

typedef stackNode * stack;

stack initStack(){
    stack S = (stackNode *)malloc(sizeof(stackNode));
    if(!S)
        return NULL;
    S->next = NULL;
    S->data = 0;
    return S;
}

bool empty(stack S){
    return !S->next;
}

void push(stack S, dataType e){
    stack temp = (stackNode*)malloc(sizeof(stackNode));
    if(!temp)
        return;
    temp->data = e;
    temp->next = S->next;
    S->next = temp;
}

void pop(stack S){
    if(empty(S))
        return;
    stack temp = S->next;
    S->next = temp->next;
    free(temp);
    temp = NULL;
}

dataType top(stack S){
    if(empty(S)){
        printf("top error. stack empty\n");
        return 0;
    }
    return S->next->data;
}

void makeEmpty(stack S){
    while(S->next){
        pop(S);
    }
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
