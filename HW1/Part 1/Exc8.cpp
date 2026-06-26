/* Assignment operators — demonstrates *= and chained assignments */
#include <stdio.h>           // Includes the standard input/output library so we can use printf

int main(){                  // The main function where program execution begins
        int x=2;             // Declares an integer variable 'x' and initializes it to 2
        int y;               // Declares an integer variable 'y' (currently uninitialized)
        int z;               // Declares an integer variable 'z' (currently uninitialized)

        x*=3+2;              // '+' has higher precedence than '*='. 
                             // Evaluates as: x = x * (3 + 2) -> x = 2 * 5 -> x becomes 10
        
        printf("x=%d\n", x); // Prints the current value of x. Output: x=10

        x*=y=z=4;            // Assignment goes right-to-left. 
                             // 1. z = 4
                             // 2. y = z (so y becomes 4)
                             // 3. x *= y -> x = 10 * 4 -> x becomes 40
        
        printf("x=%d\n", x); // Prints the new value of x. Output: x=40

        x=y==z;              // '==' has higher precedence than '='.
                             // Evaluates as: x = (y == z). 
                             // Since y (4) equals z (4), (y == z) is true, which evaluates to 1 in C.
                             // Therefore, x becomes 1.
        
        printf("x=%d\n", x); // Prints the final value of x. Output: x=1
        
        return 0;            // Returns 0 to the operating system, indicating successful execution
    };                       // Note: The semicolon here is an empty statement and is syntactically valid, though generally omitted after a function body.