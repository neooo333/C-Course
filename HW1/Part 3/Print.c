#include <stdio.h>

extern int i;

void print(void) {
    printf("%d\n", i * 2);
}
