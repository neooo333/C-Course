#ifndef DEFS_H  // include guard: prevent multiple inclusion 
#define DEFS_H

#include <stdio.h> // importing stdio.h for printf functions

// PRINT1 / PRINT2: print one or two integers 
#define PRINT1(a) printf("a = %d\n", a)
#define PRINT2(a, b) printf("a = %d, b = %d\n", a, b)

// MAX2: larger of two values; MAX3: larger of three (via MAX2) 
#define MAX2(x, y) ((x) > (y) ? (x) : (y))
#define MAX3(x, y, z) MAX2(MAX2((x), (y)), (z))

#endif
