#include <stdlib.h>
#include <string.h>
#include "stdio.h"

void memory() {
    int x = 10;
    void *p = &x; // 整数指针转为 void 指针
    int *q = p; // void 指针转为整数指针
    *q = 1;
    printf("%d\n", *q);

    int *p2 = malloc(sizeof(int));
    *p2 = 12;
    printf("%d\n", *p2); // 12

    int *p3 = (int *) malloc(sizeof(*p3));
    *p3 = 13;
    printf("%d\n", *p3);

    int n = 5;
    int *p4 = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < 5; ++i) {
        p4[i] = i;
    }
    printf("%d\n", p4[4]);

    free(p4);

    int *p5 = calloc(10, sizeof(int));
    printf("%d\n", p5[9]);

    int *b;
    b = malloc(sizeof(int) * 10);
    b = realloc(b, sizeof(int) * 2000);

    int *a = calloc(100, sizeof(int));
    a[1] = 1;
    memmove(&a[0], &a[1], 99 * sizeof(int));
    printf("%d\n", a[0]);
}
