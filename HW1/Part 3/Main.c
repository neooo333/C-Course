// Entry point; calls print() defined in Print.c
#include <stdio.h>

void print(void);

int i = 5; // Global variable shared with Print.c

int main() {
    print();
    return 0;
}
