#include <stdio.h>


int main () {

    printf ("Assigning x =5 \n");
    int x = 5;

    int i = --x;

    printf ("Value of i  of int i = --x: %d \n", i);

    printf ("Reassign x to 5 again \n");

    x = 5;
    i = x--;

    printf ("Value of i  of int i = x--: %d \n", i);

    return 0;

}