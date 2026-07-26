// Defines an Article struct and prints its fields via a pointer
#include <stdio.h>


// Article struct constructor
struct Article {
    int article_number;
    int quantity;
    char description [20];
};

//Print Article fields through a pointer
void Print (struct Article *test){

    printf ("Article Number: %d\n", (*test).article_number);
    printf ("Article Quantity: %d\n", (*test).quantity);
    printf ("Article Description: %s\n", (*test).description);
}



int main (){

    // initilize instance of the Article struct
    struct Article art1 = {123, 5, "Pencil"};

    Print (&art1); // Passing address of a struct 


    return 0;
}
