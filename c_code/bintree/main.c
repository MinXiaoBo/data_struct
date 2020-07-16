/**************************************************
*- Author       : aゞ小波
*- CreateTime   : 2019-09-23 00:09
*- Email        : 465728296@qq.com
*- Filename     : main.c
*- Description  :
***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bintree.h"

int main(int argc, char ** argv){
    int array[10] = {8,3,10,13,14,1,6,7,4,5};
    int arr_len = 10;
    binTree T = NULL;
    T = initBinTree(array, arr_len);
    travIn(T);
    return 0;
}


