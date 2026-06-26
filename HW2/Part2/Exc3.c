/* Pointer arithmetic demo — predicts printed output for each loop */
#include <stdio.h>
#define PRD(a) printf("%d", (a) ) // Print decimal
#define NL printf("\n"); // Print new line
// Create and initialse array
int a[]={0, 1, 2, 3, 4};
int main()
{
int i;
int* p;
for (i=0; i<=4; i++) PRD(a[i]); // 1: 01234 - prints array elements by index
NL;
for (p=&a[0]; p<=&a[4]; p++) PRD(*p); // 2: 01234 - walks pointer from first to last element
NL;
NL;
for (p=&a[0], i=0; i<=4; i++) PRD(p[i]); // 3: 01234 - p[i] is the same as *(p + i)
NL;
for (p=a, i=0; p+i<=a+4; p++, i++) PRD(*(p+i)); // 4: 024 - p and i both move, so it prints a[0], a[2], a[4]
NL;
NL;
for (p=a+4; p>=a; p--) PRD(*p); // 5: 43210 - walks pointer backward
NL;
for (p=a+4, i=0; i<=4; i++) PRD(p[-i]); // 6: 43210 - negative index moves backward from a[4]
NL;
for (p=a+4; p>=a; p--) PRD(a[p-a]); // 7: 43210 - p-a gives the current array index
NL;
return 0;
}