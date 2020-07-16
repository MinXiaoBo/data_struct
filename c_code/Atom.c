/**************************************************
*- Author       : aゞ小波
*- CreateTime   : 2019-11-20 22:40
*- Email        : 465728296@qq.com
*- Filename     : Atom.c
*- Description  :
***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "assert.h"
#include "mem.h"
#include "Atom.h"

#define NELEMS(x) ((sizeof(x) / sizeof((x)[0])))

static struct atom {
    struct atom * link;
    int len;
    char * str;
}* buckets[2048];

const char * Atom_string(const char * str){
    assert(str);
    return Atom_new(str, strlen(str));
}

const char * Atom_int(long n){
    char str[43];
    char *s = str + sizeof(str);
    unsigned long m;

    if(n == LONG_MIN)
        m = LONG_MAX + 1UL;
    else if(n < 0)
        m = -n;
    else
        m = n;
    do
        *--s = m%10 + '0';
    while(m / 10 > 0);
    if(n < 0)
        *--s = '-';
    return Atom_new(s, (str + sizeof(str)) - s);
}

const char * Atom_new(const char * str, int len){
    unsigned long h;
    int i;
    struct atom * p;

    assert(str);
    assert(len > 0);
    for(h = 0, i = 0; i < len; i++){
        h = (h << 1) + scatter[(unsigned char)str[i]];
    }
    h %= NELEMS(buckets);
    for(p = buckets[h]; p; p = p->link){
        if(len == p->len){
            for(i = 0; i < len && p->str[i] == str[i];)
                i++;
            if(i == len)
                return p->str;
        }
    }
    p = ALLOC(sizeof(*p) + len + 1);
    p->len = len;
    p->str = (char *)(p + 1);
    if(len > 0)
        memcpy(p->str, str, len);
    p->str[len] = '\0';
    p->link = buckets[h];
    buckets[h] = p;
    return p->str;
}

int Atom_length(const char * str){
    struct atom * p;
    int i;

    assert(str);
    for(i = 0; i < NELEMS(buckets); i++)
        for(p = buckets[i]; p; p = p->link)
            if(p->str == str)
                return p->len;
    assert(0);
    return 0;
}

int main(int argc, char ** argv){

	exit(0);
}



