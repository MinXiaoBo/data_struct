#include <stdio.h>
#include <stdlib.h>

int list[] = {2, 5, 1, 10, 6, 8, 3, 4, 13, 11};

void swap(int * a, int * b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int bubble(int lo, int hi){
    int last = lo;
    while(++lo < hi){
        if(list[lo-1] > list[lo]){
            last = hi;
            swap(&list[lo-1], &list[lo]);
        }
    }
    return last;
}

void bubblesort(int lo, int hi){
    while(lo < (hi = bubble(lo, hi)));
}

int main(int argc, char * argv[]){
    for(int i = 0; i < 10; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
    bubblesort(0, 10);
    for(int i = 0; i < 10; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
    return 0;
}
