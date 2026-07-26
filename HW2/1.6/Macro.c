// demonstrate PRINT1 and PRINT2 macros from Defs.h */
#include "Defs.h"

int main(void)
{
    // Initial values
    int a = 5;
    int b = 10;

    PRINT1(a);  // prints a 
    PRINT2(a, b);    //prints a and b 

    return 0;
}
