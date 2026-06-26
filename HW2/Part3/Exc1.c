// Defines an Article struct and prints its fields via a pointer
#include <stdio.h>


struct Article {
    int article_number;
    int quantity;
    char description [20];
};

void Print (struct Article *test){

    printf ("Article Number: %d\n", (*test).article_number);
    printf ("Article Quantity: %d\n", (*test).quantity);
    printf ("Article Description: %s\n", (*test).description);
}



int main (){

    struct Article art1 = {123, 5, "Pencil"};

    Print (&art1);


    return 0;
}