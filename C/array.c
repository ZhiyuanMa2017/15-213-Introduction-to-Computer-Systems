#include <stdio.h>
#include <string.h>
#include "stdlib.h"
int sum(const int *arr, int len) {
    int sum = 0;
    for (int i = 0; i < len; ++i) {
        sum += arr[i];
    }
    return sum;
}

int sum2(const int *arr, int len) {
    int sum = 0;
    for (int i = 0; i < len; ++i) {
        sum += *(arr + i);
    }
    return sum;
}

void print(long d) {
    printf("%ld\n", d);
}

void printS(long d) {
    printf("%ld ", d);
}

void p() {
    printf("\n");
}

void array() {
    int a[] = {22, 37, 3490};
    int arrLen = sizeof(a); // 12
    printf("size of array: %d\n", arrLen);

    int a2[5] = {11, 22, 33, 44, 55};

    int *p1 = &a2[0];
    int *p2 = a2;
    if (p1 == p2) {
        printf("same address\n");
    }
    printf("sum: %d\n", sum(a2, 5));
    printf("sum2: %d\n", sum2(a2, 5));

    int *p3 = a2;
    while (*p3 != 33) {
        printS(*p3);
        p3++;
    }

    int *p4 = a2;
    while (*p4 != 44) {
        p4++;
    }
    p();
    print(p4 - a2);

    print(&a2[4] - &a2[0]);

    int a3[sizeof a2];
    memcpy(a3, a2, sizeof a2);
    print(*(a3 + 1));
}
