#include <iostream>
#include <ctime>


#define random_int(x) (rand() % (x+1))

typedef int data_type;

void merge(int arr[], int low, int mid, int high){
    int i, k;
    int *tmp = (int *)malloc((high-low+1)*sizeof(int));
    int left_low = low;
    int left_high = mid;
    int right_low = mid + 1;
    int right_high = high;
    for(k = 0; left_low <= left_high && right_low <= right_high; k++){
        if(arr[left_low]<=arr[right_low]){
            tmp[k] = arr[left_low++];
        }else{
            tmp[k] = arr[right_low++];
        }
    }
    if(left_low <= left_high){
        for(i = left_low; i <= left_high; i++)
            tmp[k++] = arr[i];
    }
    if(right_low <= right_high){
        for(i = right_low; i <= right_high; i++)
            tmp[k++] = arr[i];
    }
    for(i = 0; i < high - low + 1; i++)
        arr[low+i] = tmp[i];
    free(tmp);
    return;
}

data_type * merge_sort(data_type * arr, int first, int last){
    int mid = 0;
    if(first < last){
        mid = (first + last) / 2;
        merge_sort(arr, first, mid);
        merge_sort(arr, mid + 1, last);
        merge(arr, first, mid, last);
    }
    return arr;
}

void average(int n){
    int num_arr[n];
    for(int i = 0; i < n; i++){
        num_arr[i] = random_int(n);
    }
    clock_t strat_time = clock();
    merge_sort(num_arr, 0, n-1);
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
    merge_sort(num_arr, 0, n-1);
    clock_t end_time = clock();
    double use_time = (double)(end_time - strat_time);
    printf("good_use_time:%f\n", use_time);
}

void bad(int n){
    int num_arr[n];
    for(int i = 0; i < n; i++){
        num_arr[i] = n - 1 - i;
    }
    clock_t strat_time = clock();
    merge_sort(num_arr, 0, n-1);
    clock_t end_time = clock();
    double use_time = (double)(end_time - strat_time);
    printf("bad_use_time:%f\n", use_time);
}

int main(int argc, char * argv[]){
    srand((unsigned)time(NULL));
    int n = 10000;
    average(n);
    bad(n);
    good(n);
    return 0;
}
