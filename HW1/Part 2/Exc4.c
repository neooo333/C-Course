// Prints a Fahrenheit-to-Celsius conversion table
#include <stdio.h>


double celsius_conversion (int f_degree){

    double cel;
    double ratio = 5.0 / 9.0;
    cel = ratio * (f_degree - 32);
    return cel;
}

int main (){

// Input Parameters

    int start = 0;
    int step = 20;
    int stop = 300;

    int iter_temp = start;

    if (stop< start){
        printf ("Start cannot be less than Stop \n");
        return 0;
    }

    printf ("Fahrenheit \t Celsius \n");
    while (iter_temp <= stop){
        printf ("%d \t %10.1f \n", iter_temp, celsius_conversion (iter_temp));
        iter_temp += step;
    }
    return 0;
}
