#include "linklist.h"

#define random(x) (rand() % x)

int main(){
    linkNode mylist;
    linkList List = &mylist;
	initList(List);

    dataType e = 0;

    for(int i = 0; i < 100; i++){
        e = (dataType)random(100);
        //append(List, e);
        insert(List, e, i+1);
    }
	printList(List);

	printf("list length is %d\n", size(List));
	//reverseR(List, 4);
	//printList(List);
    //removeByData(List, 2);
    //Rank res = removeAllByData(List, 4);
    //printf("res: %d\n", res);
	//printList(List);
	//reversePrintList(List);
	//printList(List);
	return 0;
}
