#include <iostream>
#include <ctime>

#define random_int(x) (rand() % (x+1))

typedef int data_type;

data_type * insertion_sort(data_type * arr, int n){
    int i,j;
    int temp;
    for(i = 1; i < n; i++){
        temp = arr[i];
        for(j = i - 1; j >= 0 && temp < arr[j]; j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = temp;
    }
    return arr;
}

void average(int n){
    int num_arr[n];
    for(int i = 0; i < n; i++){
        num_arr[i] = random_int(n);
    }
    clock_t strat_time = clock();
    insertion_sort(num_arr, n);
    clock_t end_time = clock();
    double use_time = (double)(end_time - strat_time);
    printf("average_use_time:%f\n", use_time);
    //for(int i = 0; i < n; i++){
    //    printf("%d ", num_arr[i]);
    //}
    //printf("\n");
}

void bad(int n){
    int num_arr[n];
    for(int i = 0; i < n; i++){
        num_arr[i] = n - i;
    }
    clock_t strat_time = clock();
    insertion_sort(num_arr, n);
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
    insertion_sort(num_arr, n);
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
