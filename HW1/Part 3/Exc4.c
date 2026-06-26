// Prints an integer digit-by-digit using recursion (no printf %d)
#include <stdio.h> 

void printnumber(int n) {

    if (n < 0) {
        putchar('-');
        n = -n; 
    }

    if (n / 10 != 0) {
        printnumber(n / 10); 
    }

   
    putchar((n % 10) + '0');
}

int main() {
    printnumber(12345);
    putchar('\n'); 
    
    printnumber(-987);
    putchar('\n'); 
    
    printnumber(0);
    putchar('\n'); 

    return 0;
}