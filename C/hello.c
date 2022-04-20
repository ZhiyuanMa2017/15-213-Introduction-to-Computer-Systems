#include <stdio.h>

#include "limits.h"

void hello() {
    printf("\a");
    printf("%d\n", SCHAR_MAX);
    printf("%d\n", SCHAR_MIN);
    printf("%d\n", SHRT_MAX);
    printf("%d\n", SHRT_MIN);
    printf("%d\n", INT_MAX);
    printf("%d\n", INT_MIN);
    printf("%ld\n", LONG_MAX);
    printf("%ld\n", LONG_MIN);
    printf("%lld\n", LLONG_MAX);
    printf("%lld\n", LLONG_MIN);

    printf("%d\n", UCHAR_MAX);
    printf("%d\n", USHRT_MAX);
    printf("%d\n", UINT_MAX);
    printf("%lu\n", ULONG_MAX);
    printf("%llu\n", ULLONG_MAX);
    int x = 100;
    printf("dec = %d\n", x); // 100
    printf("octal = %o\n", x); // 144
    printf("hex = %x\n", x); // 64
    printf("octal = %#o\n", x); // 0144
    printf("hex = %#x\n", x); // 0x64
    printf("hex = %#X\n", x); // 0X64
    x = 1;
    if (x) {
        printf("x is true!\n");
    }
    int a = 1234;
    long int b = 1234L;
    long long int c = 1234LL;

    unsigned int e = 1234U;
    unsigned long int f = 1234UL;
    unsigned long long int g = 1234ULL;

    float h = 3.14f;
    double i = 3.14;
    long double j = 3.14L;
    unsigned char k = 255;
    k = k + 1;

    printf("%d\n", k); // 0
    unsigned int ui = UINT_MAX;  // 4,294,967,295
    ui++;
    printf("ui = %u\n", ui); // 0
    ui--;
    printf("ui = %u\n", ui); // 4,294,967,295
    printf("%zd\n", sizeof(int));

    int32_t x32 = 45933945;
    printf("x32 = %d\n", x32);
    int l = 1;
    printf("l's address is %p\n", &l);
    if (l == *(&l)) {
        printf("true\n");
    }

    int *p = NULL;
    int m;
    p = &m;
    *p = 1;
    printf("%d\n", m);
    printf("d\n");
}