// Prints "Married" or "Not Married" based on user input
#include "stdio.h"

int main () {


    int married;


    printf ("Enter 1 if married and 0 otherwise \n");
    scanf ("%d", &married);

    printf ("%s \n", married ?"Married" : "Not Married");

    return 0;
}