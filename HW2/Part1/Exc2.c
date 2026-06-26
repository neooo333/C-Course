// Demonstrates MAX2 and MAX3 macros from Defs.h
#include "Defs.h"


int main (){

    int a = 10;
    int b = 13;
    int c = 12;

    printf ("Max of 2 numbers: %d \n", MAX2(a, b));
    printf ("Max of 3 numbers: %d \n", MAX3(a, b, c));

    return 0;
}