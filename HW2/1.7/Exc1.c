// swap two integers using pointers 
#include <stdio.h>

/* Exchange the values of the two integers pointed to by x and y */
void Swap(int *x, int *y)
{
    // Assigning value of x to temp
    int temp = *x;
    // Switching vlaues
    *x = *y;
    *y = temp;
}

int main(void)
{
    // Initial values
    int a = 20;
    int b = 30;

    printf("Original values: a = %d, b = %d\n", a, b);

    Swap(&a, &b);  // pass addresses so Swap can modify a and b 

    printf("New values: a = %d, b = %d\n", a, b); // printing ouput

    return 0;
}
