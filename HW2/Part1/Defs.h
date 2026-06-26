#ifndef DEFS_H
#define DEFS_H

#include <stdio.h>

#define PRINT1(a) printf("a = %d\n", a)
#define PRINT2(a, b) printf("a = %d, b = %d\n", a, b)

#define MAX2(x, y) ((x) > (y) ? (x) : (y))
#define MAX3(x, y, z) MAX2(MAX2((x), (y)), (z))

#endif

