// Evaluates arithmetic expressions and prints x after each step
#include <stdio.h> // Includding standard liabrary to print off info in console


int main(){ // Start main function that will be executted when we run our script 

    int x; // Declare variable x as integer but not initialize it  yet

    x=-3+4*5-6; //assign int value to x whcih is equal to value of the expreession (11)

    printf("x=%d\n", x);  /*print off value x as integer (%d) in conslole. 
    Use fstring to add value to the text. Expected output on the screen "X=11"
    */ 
    x=3+4%5-6; // Reassign value to x that will be eqaul to the expession. Since reminder of 4/5 is 4 the value of x = 1


    printf("x=%d\n", x); // print reassined vlaue of x asv int. Expected output x=1



    x=-3*4%-6/5; // Reasign value x again. 6/5 = 1. reminder of 4/ -1 is 0. -3*0 = 0
    printf("x=%d\n", x); // Print off new vlaue of x. In this case the output is "x=0"


    x=(7+6)%5/2; // Reasin values to x. 7+6 = 13. 5/2 = 2. Remainder of 13/2 = 1
    printf("x=%d\n", x); // Print off new output. x= 1
    return 0; // retun 0 of maning that main executed successfully
}; 