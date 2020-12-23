/*************************************************************************
	> File Name: 191.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed Sep 23 21:14:52 2020
 ************************************************************************/

#include <stdio.h>
#include <malloc.h>

int *extract_prime(int min, int max) {
    int *num = (int *) calloc(max + 1, sizeof(int));
    int count = 0;
    for (int i = 2; i * i <= max; i++) {
        for (int j = min / i; j <= max / i; j++) {
            if (!num[i * j] && i * j >= min) ++count;
            num[i * j] = 1;
        }
    }
    int *prime = (int *) calloc(max - min + 2 - count, sizeof(int));
    int j = -1;
    for (int i = min; i <= max; i++) {
        if (!num[i]) prime[++j] = i;
    }
    free(num);
    num = NULL;
    if (j < 1) return num;
    else return prime;
}

void distant(int *prime) {
    int min, max, min_left, max_left, min_right, max_right, i = 1;
    min = max = prime[1] - prime[0];
    min_left = max_left = prime[0];
    min_right = max_right = prime[1];
    while(prime[i]) {
        if (prime[i] - prime[i - 1] > max) {
            max = prime[i] - prime[i - 1];
            max_left = prime[i - 1];
            max_right = prime[i];
        } else if (prime[i] - prime[i -1] < min) {
            min = prime[i] - prime[i -1];
            min_left = prime[i - 1];
            min_right = prime[i];
        }
        ++i;
    }
    printf("%d,%d are closest, %d,%d are most distant.\n", min_left, min_right, max_left, max_right);
}

int main() {
    int l, r;
    scanf("%d%d", &l, &r);
    if (extract_prime(l, r) != NULL) {
        int *prime = extract_prime(l, r);
        distant(prime);
    } else printf("There are no adjacent primes.\n");
    return 0;
}
