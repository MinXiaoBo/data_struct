#include "linklist.h"

void initList(linkList header){
    if(!header){
        return;
    }
    header->next = NULL;
    header->data = 0;
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
    if(index != r - 1)
        return -1;
    linkList temp = (linkList)malloc(sizeof(linkNode));
    if(!temp)
        return -1;
    temp->data = e;
    temp->next = head_t->next;
    head_t->next = temp;
    return r;
}

void append(linkList header, dataType e){
    Rank lenght = size(header);
    insert(header, e, lenght+1);
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

Rank removeByData(linkList header, dataType e){
    linkList head_t = header;
    linkList head_n = header->next;
    Rank index = 1;
    while(head_n && e != head_n->data){
        head_n = head_n->next;
        head_t = head_t->next;
        index++;
    }
    if(!head_n)
        return -1;
    head_t->next = head_n->next;
    free(head_n);
    return index;
}

void removeAllByData_R(linkList header, dataType e){
    linkList head_t = header->next;
    if(head_t == NULL)
        return;
    if(head_t->data == e){
        header->next = head_t->next;
        free(head_t);
        removeAllByData_R(header, e);
    }else{
        removeAllByData_R(head_t, e);
    }
}

int removeAllByData(linkList header, dataType e){
    int count = 0;
    while(removeByData(header, e) != -1){
        count++;
    }
    return count;
}

void reverse(linkList header){
    linkList head_t = header->next;
    header->next = NULL;
    while(head_t != NULL){
        insert(header, head_t->data, 1);
        head_t = head_t->next;
    }
}

linkList locNode(linkList header, dataType e){
    linkList head_t = header->next;
    while(head_t && head_t->data != e){
        head_t = head_t->next;
    }
    return head_t;
}

linkList getNode(linkList header, Rank r){
    Rank index = 0;
    linkList head_t = header;
    while(head_t->next && index < r){
        head_t = head_t->next;
        index++;
    }
    if(r != index)
        return NULL;
    return head_t;
}

void printList(linkList header){
    linkList head_t = header->next;
    while(head_t){
        printf("%d ", head_t->data);
        head_t = head_t->next;
    }
    printf("\n");
}

void reversePrintList(linkList header){
    linkList head_t = header->next;
    if(!head_t)
        return;
    reversePrintList(head_t);
    printf("%d ", head_t->data);
}
