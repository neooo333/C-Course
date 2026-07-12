// Subtracts two doubles using a helper function
#include <stdio.h>


double minus (double first_variable, double second_variable){

    double result;
    result = first_variable - second_variable;
    return result;

}

int main (){

    double first_v;
    double second_v;
    double final_result;

    printf ("Enter first variable \n");
    scanf ("%lf", &first_v);

    printf ("Enter second variable \n");
    scanf ("%lf", &second_v);

    final_result = minus (first_v, second_v);

    printf ("The difference: %lf \n", final_result);

    return 0;
}