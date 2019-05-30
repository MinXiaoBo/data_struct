#include "linklist.h"

linkList initList(){
    linkNode myList;
    linkList header = &myList;
    if(! header){
        return NULL;
    }
    header->next = NULL;
    header->data = 0;
    return header;
}

void destroyList(linkList header){
    linkList head_t = header->next;
    linkList temp = NULL;
    while(head_t != NULL){
        temp = head_t;
        head_t = head_t->next;
        free(temp);
    }
}

bool empty(linkList header){
    return !header;
}

Rank size(linkList header){
    linkList head_t = header->next;
    Rank size = 0;
    while(head_t != NULL){
        size++;
        head_t = head_t->next;
    }
    return size;
}

Rank insert(linkList header, dataType e, Rank r){
    linkList head_t = header;
    Rank index = 0;
    while(head_t->next && index < r -1){
        head_t = head_t->next;
        index++;
    }
    if(index != r -1)
        return -1;
    linkList temp = (linkList)malloc(sizeof(linkNode));
    if(!temp)
        return -1;
    temp->data = e;
    temp->next = head_t->next;
    head_t->next = temp;
    return r;
}

dataType removeByIndex(linkList header, Rank r){
    linkList head_t = header;
    Rank index = 0;
    while(head_t->next && index < r -1){
        head_t = head_t->next;
        index++;
    }
    if(index != r -1)
        return -1;
    linkList temp = head_t->next;
    dataType e = temp->data;
    head_t->next = temp->next;
    free(temp);
    return e;
}
