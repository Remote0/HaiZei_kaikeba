/*************************************************************************
	> File Name: string_match.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 13 Jan 2021 09:48:05 AM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

int brute_force(const char *s, const char *t) {
    for (int i = 0; s[i]; i++) {
        int flag = 1;
        for (int j = 0; t[j] && flag; j++) {
            flag = flag && (s[i + j] == t[j]);
        }
        if (flag == 1) return i;
    }
    return -1;
}

int getNext(const char *t, int &j, char input, int *next) {
    while (j != -1 && t[j + 1] != input) j = next[j];
    if (t[j + 1] == input) j += 1;
    return j;
}

int kmp(const char *s, const char *t) {
    int n = strlen(t);
    int *next = (int *)malloc(sizeof(int) * n + 1);
    next[0] = -1;
    for (int i = 1, j = -1; t[i]; i++) next[i] = getNext(t, j, t[i], next);
    for (int i = 0, j = -1; s[i]; i++) {
        if (getNext(t, j, s[i], next) != n - 1) continue;
        return i - n + 1;
    }
    free(next);
    return -1;
}

/*
void getNext(const char *t, int *next) {
    next[0] = -1;
    int j = -1;
    for (int i = 1; t[i]; i++) {
        while (j != -1 && t[j + 1] != t[i]) j = next[j];
        if (t[j + 1] == t[i]) j += 1;
        next[i] = j;
    }
    return ;
}

int kmp(const char *s, const char *t) {
    int n = strlen(t);
    int *next = (int *)malloc(sizeof(int) * (n + 1));
    getNext(t, next);
    for (int i = 0, j = -1; s[i]; i++) {
        while (j != -1 && s[i] - t[j + 1]) j = next[j];
        if (s[i] == t[j + 1]) j += 1;
        if (t[j + 1] == 0) return i - n + 1;
    }
    free(next);
    return -1;
}
*/
int sunday(const char *s, const char *t) {
    int offset[256];
    int n = strlen(t), m = strlen(s);
    for (int i = 0; i < 256; i++) offset[i] = n + 1;
    for (int i = 0; t[i]; i++) offset[t[i]] = n - i;
    for (int i = 0; i + n <= m; i += offset[s[i + n]]) {
        int flag = 1;
        for (int j = 0; t[j] && flag; j++) {
            flag = flag && (s[i + j] == t[j]);
        }
        if (flag) return i;
    }
    return -1;
}

int shift_and(const char *s, const char *t) {
    int d[256] = {0}, n = 0;
    for (int i = 0; t[i]; n++, i++) d[t[i]] |= (1 << i);
    int p = 0;
    for (int i = 0; s[i]; i++) {
        p =  (p << 1 | 1) & d[s[i]];
        if (p & (1 << (n - 1))) return i - n + 1;
    }
    return -1;
}

int main() {
    char s[100], t[100];
    while (~scanf("%s%s", s, t) != EOF) {
        printf("brute_force(%s, %s) = %d\n", s, t, brute_force(s, t));
        printf("kmp(%s, %s) = %d\n", s, t, kmp(s, t));
        printf("sunday(%s, %s) = %d\n", s, t, sunday(s, t));
        printf("shift_and(%s, %s) = %d\n", s, t, shift_and(s, t));
    }
    return 0;
}
