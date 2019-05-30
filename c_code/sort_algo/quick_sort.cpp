#include <iostream>
#include <ctime>

#define random_int(x) (rand() % (x+1))

typedef int data_type;

data_type * quick_sort(data_type * arr,int low, int high){
    if(low < high){
        int i= low, j = high;
        data_type temp = arr[i];
        while(i < j){
            while(i < j && arr[j] >= temp)
                if(i < j)
                    j--;
            arr[i] = arr[j];
            while(i < j && arr[i] <= temp)
                if(i < j)
                    i++;
            arr[j] = arr[i];
        }
        arr[i] = temp;
        quick_sort(arr, low, i-1);
        quick_sort(arr, i+1, high);
    }
    return arr;
}

void average(int n){
    int num_arr[n];
    for(int i = 0; i < n; i++){
        num_arr[i] = random_int(n);
    }
    clock_t strat_time = clock();
    quick_sort(num_arr, 0, n-1);
    clock_t end_time = clock();
    double use_time = (double)(end_time - strat_time);
    printf("average_use_time:%f\n", use_time);
    //for(int i = 0; i < n; i++){
    //    printf("%d ", num_arr[i]);
    //}
    //printf("\n");
}

void good(int n){
    int num_arr[n];
    for(int i = 0; i < n; i++){
        num_arr[i] = i;
    }
    clock_t strat_time = clock();
    quick_sort(num_arr, 0, n-1);
    clock_t end_time = clock();
    double use_time = (double)(end_time - strat_time);
    printf("good_use_time:%f\n", use_time);
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
    quick_sort(num_arr, 0, n-1);
    clock_t end_time = clock();
    double use_time = (double)(end_time - strat_time);
    printf("bad_use_time:%f\n", use_time);
}

int main(int argc, char * argv[]){
    srand((unsigned)time(NULL));
    int n = 100;
    average(n);
    bad(n);
    good(n);
    return 0;
}
