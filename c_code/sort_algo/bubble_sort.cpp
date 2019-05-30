#include <iostream>
#include <ctime>

#define random_int(x) (rand() % (x+1))

typedef int data_type;

//data_type * bubble_sort(int * arr, int n){
//    int i, j, temp;
//    for(i = 0; i < n - 1; i++){
//        for(j = 0; j < n - 1 - i; j++){
//            if(arr[j] > arr[j+1]){
//                temp = arr[j+1];
//                arr[j+1] = arr[j];
//                arr[j] = temp;
//            }
//        }
//    }
//    return arr;
//}


void swap(int * a, int * b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

bool bubble(int * array, int lo, int hi){
    bool sorted = true;
    while(++lo < hi){
        if(array[lo-1] > array[lo]){
            sorted = false;
            swap(&array[lo-1], &array[lo]);
        }
    }
    return sorted;
}

void bubble_sort(int * array, int lo, int hi){
    while(!bubble(array, lo, hi--));
}

void average(int n){
    int num_arr[n];
    for(int i = 0; i < n; i++){
        num_arr[i] = random_int(n);
    }
    clock_t strat_time = clock();
    bubble_sort(num_arr, 0, n);
    clock_t end_time = clock();
    double use_time = (double)(end_time - strat_time);
    printf("average_use_time:%f\n", use_time);
    for(int i = 0; i < n; i++){
        printf("%d ", num_arr[i]);
    }
    printf("\n");
}

void bad(int n){
    int num_arr[n];
    for(int i = 0; i < n; i++){
        num_arr[i] = n - i;
    }
    clock_t strat_time = clock();
    bubble_sort(num_arr, 0, n);
    clock_t end_time = clock();
    double use_time = (double)(end_time - strat_time);
    printf("bad_use_time:%f\n", use_time);
}

void good(int n){
    int num_arr[n];
    for(int i = 0; i < n; i++){
        num_arr[i] = i;
    }
    clock_t strat_time = clock();
    bubble_sort(num_arr, 0, n);
    clock_t end_time = clock();
    double use_time = (double)(end_time - strat_time);
    printf("good_use_time:%f\n", use_time);
}

int main(int argc, char * argv[]){
    srand((unsigned)time(NULL));
    int n = 10000;
    average(n);
    bad(n);
    good(n);
    return 0;
}
