/*************************************************************************
	> File Name: 1.pthread.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 12 Apr 2021 07:12:03 PM CST
 ************************************************************************/

#include "head.h"
#define INS 100

struct Arg{
    int age;
    char name[20];
};

void *print(void *arg) {
    struct Arg argin;
    argin = *(struct Arg *)arg;
    printf("%s is %d years old!\n", argin.name, argin.age);
}

int main() {
    pthread_t *tid = calloc(INS + 5, sizeof(pthread_t));
    struct Arg *arg = calloc(INS + 5, sizeof(struct Arg));
    for (int i = 1; i <= 100; i++) {
        strcpy(arg[i - 1].name, "cuiguochong");
        arg[i - 1].age = i;
        pthread_create(&tid[i - 1], NULL, print, &arg[i - 1]);
    }
    for (int i = 0; i < 100; i++) {
        pthread_join(tid[i], NULL);
    }
    return 0;
}
