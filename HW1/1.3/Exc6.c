// Shifts an integer 2 bits right and reports shift type
#include <stdio.h>



int main (){

    int result;

    printf ("Enter an integer to shift 2 places to the right \n");
    scanf ("%d", &result);

    int logocal_result = result >> 2;   // >> on a signed int

    // negative result means sign bit was copied in -> arithmetic shift
    if (logocal_result < 0 ){
        printf ("The shifted value is %d. Arthimetic shift has been performed \n" , logocal_result);
    }else{
        printf ("The shifted value is %d. Logical shift has been performed \n" , logocal_result);

    }


    return 0;
}