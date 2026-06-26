// Prints a Celsius-to-Fahrenheit conversion table (0–19)
#include <stdio.h>


double fahrenheit_conversion (int c_degree){

    double fah;
    double ratio = 9.0 / 5.0;
    fah = (ratio * c_degree) + 32;
    return fah;
}

int main (){

// Input Parameters


    printf ("Celsius \t Fahrenheit \n");

     for (int i = 0; i <= 19; i++){

        printf ("%d \t %10.1f \n", i, fahrenheit_conversion (i));
    }
    return 0;
}
