#include <stdlib.h>
#include "stdio.h"


extern void hello(void);

extern void array(void);

extern void string(void);

extern void memory(void);

char *toBinary(int n, int len) {
    char *binary = (char *) malloc(sizeof(char) * len);
    int k = 0;
    for (unsigned i = (1 << (len - 1)); i > 0; i = i / 2) {
        binary[k++] = (n & i) ? '1' : '0';
    }
    binary[k] = '\0';
    return binary;
}

void print(int x) {
    int len = 32;
    char *b = toBinary(x, len);
    printf("%d %s\n", x, b);
    free(b);
}

int isLessOrEqual(int x, int y) {
    /*
     * a < 0, b > 0 => true
     * a > 0, b < 0 => false
     * minus and check first bit
     */
    int a = (x >> 31) & 1;
    int b = (y >> 31) & 1;
    int ab = a & !b;
    int ba = (!a) & b;
    int z = y + ~x + 1;
    int firstBit = z >> 31;
    return ab | ((!ba) & (!firstBit));
}

int logicalNeg(int x) {
    int a = x >> 31;
    int b = 0 + ~x + 1;
    int c = b >> 31;
    return (a + 1) & (c + 1);
}

int howManyBits(int x) {
    int b16, b8, b4, b2, b1, b0;
    int shift16, shift8, shift4, shift2, shift1;
    int firstBit = x >> 31;
    x = (~firstBit & x) | (firstBit & ~x);

    shift16 = x >> 16;
    b16 = (!!shift16) << 4;
    x = x >> b16;

    shift8 = x >> 8;
    b8 = (!!shift8) << 3;
    x = x >> b8;

    shift4 = x >> 4;
    b4 = (!!shift4) << 2;
    x = x >> b4;

    shift2 = x >> 2;
    b2 = (!!shift2) << 1;
    x = x >> b2;

    shift1 = x >> 1;
    b1 = (!!shift1);
    x = x >> b1;

    b0 = x;

    return 1 + b0 + b1 + b2 + b4 + b8 + b16;
}

int main() {
//    hello();
//    array();
//    string();
//    memory();
    int x = -2147483648;
    int y = 2147483647;
    int c = y - x;
    print(howManyBits(x));
}