// Computes factorial of a number using recursion
#include <stdio.h>


long int factorial ( long int fact){

    if (fact <= 1)
        return 1;
    return  fact * factorial (fact-1);
}




int main (){

    long int value;

    printf ("Input factorial number as int: ");
    scanf ("%ld", &value);

    printf ("%ld\n", factorial (value));
    return 0;
}