#include "stdio.h"
#include "string.h"

void string() {
    char string[10] = "hello";
    printf("%s\n", string);
    char s[] = "Aello, world!";
    s[0] = 'H';
    printf("%s\n", s);
    const char *s2 = "Hello, world!";// can not change

    char s3[10];
    strcpy(s3, "abc");

    char *str = "Hello, world!";
    int len = strlen(str);
    printf("%d\n", len);

    int cmp = strcmp(str, s);
    printf("%d\n", cmp);

    char first[6] = "hello";
    char last[6] = "world";
    char s4[40];
    sprintf(s4, "%s %s", first, last);
    printf("%s\n", s4); // hello world

    char *weekdays[] = {
            "Monday",
            "Tuesday",
            "Wednesday",
            "Thursday",
            "Friday",
            "Saturday",
            "Sunday"
    };
    for (int i = 0; i < 7; i++) {
        printf("%s\n", weekdays[i]);
    }
}
