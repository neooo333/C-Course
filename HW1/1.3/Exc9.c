/* Conditional expressions — ternary operator and side effects */
#include <stdio.h>

int main()
{
    int x=1;
    int y=1;
    int z=1; // Declared but unused

    x+=y+=x; // Right-to-left: first y = y+x (1+1=2), then x = x+y (1+2=3). Now x=3, y=2.
    
    printf("%d\n\n", (x<y)?y:x);   // (3 < 2) is false. Prints x. Output: 3 (Add two empty lines after)
    
    printf("%d\n", (x<y)?x++:y++); // (3 < 2) is false. Prints y (2), then increments y to 3. Output: 2
    
    printf("%d\n", x);             // x is still 3. Output: 3
    
    printf("%d\n", y);             // y was incremented to 3. Output: 3

    return 0;
}