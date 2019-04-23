#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct node{
	DataType data;
	struct node *next;
}ListNode;

typedef ListNode* LinkList;

LinkList initList(){
	LinkList head = (ListNode *)malloc(sizeof(ListNode));
	if( ! head ){
		exit(-1);
	}
	head->next = NULL;
	head->data = 0;
	return head;
}

void append(LinkList head, DataType e){
	LinkList tmp = (ListNode *)malloc(sizeof(ListNode));
	if( ! tmp ){
		exit(-1);
	}
	tmp->data = e;
	tmp->next = NULL;
	LinkList head_t = head;
	while(head_t->next != NULL){
		head_t = head_t->next;
	}
	head_t->next = tmp;
}

int insert(LinkList head, int index, DataType e){
	int node_pos = 0;
	LinkList head_t = head;
	while(head_t->next && node_pos < index - 1){
		head_t = head_t->next;
		node_pos++;
	}
	if( node_pos != index - 1){
		printf("index error");
		exit(0);
	}
	LinkList tmp = (ListNode *)malloc(sizeof(ListNode));
	if( ! tmp ){
		exit(-1);
	}
	tmp->data = e;
	tmp->next = head_t->next;
	head_t->next = tmp;
	return index;
}

int removeByIndex(LinkList head, int index){
	int node_pos = 0;
	LinkList head_t = head;
	while(head_t->next && node_pos < index - 1){
		head_t = head_t->next;
		node_pos++;
	}
	if( node_pos != index - 1){
		printf("index error");
		exit(0);
	}
	LinkList tmp = head_t->next;
	head_t->next = tmp->next;
	free(tmp);
	return index;
}

DataType removeByData(LinkList head, DataType e){
	LinkList head_t = head;
	LinkList head_n = head->next;
	while(head_n && head_n->data != e){
		head_t = head_t->next;
		head_n = head_n->next;
	}
	if( head_n == NULL){
		printf("Node does not exist");
		exit(0);
	}
	head_t->next = head_n->next;
	free(head_n);
	return e;
}

DataType removeAllByData(LinkList head, DataType e){
	LinkList head_t = head;
	LinkList head_n = head->next;
	while(head_n){
		if(head_n->data == e){
			head_t->next = head_n->next;
			free(head_n);
			head_n = head_n->next;
		}else{
			head_t = head_t->next;
			head_n = head_n->next;
		}
	}
	return e;
}

void recursive(LinkList head){
	LinkList head_n = head->next;
	head->next = NULL;
	while(head_n != NULL){
		insert(head, 1, head_n->data);
		head_n = head_n->next;
	}
}

void recursive_R(LinkList head, DataType e){
	LinkList head_n = head->next;
	if( head_n == NULL){
		return ;
	}
	if( head_n->data == e){
		head->next = head_n->next;
		free(head_n);
		recursive_R(head, e);
	}else{
		recursive_R(head_n, e);
	}
}

LinkList locNode(LinkList head, DataType e){
	LinkList head_t = head->next;
	while(head_t && head_t->data != e){
		head_t = head_t->next;
	}
	return head_t;
}

LinkList getNode(LinkList head, int index){
	int node_pos = 0;
	LinkList head_t = head;
	while(head_t->next && node_pos < index){
		head_t = head_t->next;
		node_pos++;
	}
	if( node_pos != index ){
		printf("index error");
		exit(0);
	}
    return head_t;
}

int getLenght(LinkList head){
    int length = 0;
    LinkList head_t = head->next;
    while(head_t != NULL){
        head_t = head_t->next;
        length++;
    }
    return length;
}

void printList(LinkList head){
	LinkList head_t = head->next;
	while(head_t != NULL){
		printf("%d ", head_t->data);
		head_t = head_t->next;
	}
    printf("\n");
}

void reversePrintList(LinkList head){
	LinkList head_t = head->next;
	if(head_t == NULL){
		return ;
	}else{
		reversePrintList(head_t);
		printf("%d ", head_t->data);
	}
}

int main(){
	LinkList mylist = initList();
	int arr[13] = {2, 4, 1, 3, 5, 4, 7, 6, 4, 8, 0, 9, 4};
	for(int i = 0; i < 13; i++){
		append(mylist, arr[i]);
	}
	printList(mylist);
	recursive(mylist);
	//reversePrintList(mylist);
	//printf("\n");
	//printf("list length is %d\n", getLenght(mylist));
	//recursive_R(mylist, 4);
	//removeAllByData(mylist,  4);
	printList(mylist);
	return 0;
}
