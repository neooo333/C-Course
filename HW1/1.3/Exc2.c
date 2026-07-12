// Ex2: area of a right triangle = 0.5 * base * height
#include <stdio.h>


int main (){

    double height;

    double base;

    printf ("Enter the base of triangle \n");
    scanf("%lf", &base);

    printf ("Enter the height of triangle \n");
    scanf("%lf", &height);

    // 0.5 * base * height
    printf ("The area of your trianlge is: %lf \n", 0.5 * height * base);

    return 0;



};



