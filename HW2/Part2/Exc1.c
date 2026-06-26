// Swaps two integers in place using pointers
#include <stdio.h>



void Swap (int* x, int* y){

    int temp_x = *x;
    int temp_y = *y;

    *x = temp_y;
    *y = temp_x;
}


int main (void){

    int a = 20;
    int b = 30;

    printf ("Original values: a = %d, b = %d \n", a, b);

    Swap (&a, &b);

    printf ("New values: a = %d, b = %d \n", a, b);

    return 0;
}
