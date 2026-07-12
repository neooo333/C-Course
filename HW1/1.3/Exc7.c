// Multiplies a number by 2^n using left bit shift
# include <stdio.h>

int main (){

    int n; //power
    int number;
    int final_number;

    printf ("Enter integer that you would like to  multiply by 2^n: ");
    scanf ("%d", &number);

    printf ("Enter integer power of 2 that original number should be mulpiply by: ");
    scanf ("%d", &n);

    final_number = number << n;   // number * 2^n

    printf ("The shifted number: %d \n", final_number);


    return 0;
}