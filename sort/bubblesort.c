#include <stdio.h>
#include <stdlib.h>

int list[] = {2, 5, 1, 10, 6, 8, 3, 4, 13, 11};

void swap(int * a, int * b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubble(){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10 -i-1; j++){
            if(list[j] > list[j+1]){
                swap(&list[j], &list[j+1]);
            }
        }
    }
}

int main(int argc, char * ragv[]){
    for(int i = 0; i < 10; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
    bubble();
    for(int i = 0; i < 10; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
    return 0;
}
