// input lines to stdout until CTRL+A is received
#include <stdio.h>

#define CTRL_A 1  // ^A has ASCII value 1 
#define MAX_LINE_LENGTH 1000

int main(void) {
    int ch;
    char line[MAX_LINE_LENGTH];
    int length = 0;

    // Buffer chars and echo only when Enter is pressed 
    while ((ch = getchar()) != EOF) {
        if (ch == CTRL_A) { // the way to exit the while loop and finish the program
            printf("CTRL + A is a correct ending.\n");
            return 0;
        }

        // Adding text to line array. When it has "\n" input the whole line will be printed on a screen.
        if (ch == '\n') {
            /* Flush the buffered line to the screen */
            for (int i = 0; i < length; i++) {
                putchar(line[i]);
            }
            putchar('\n');
            length = 0;
        } else if (length < MAX_LINE_LENGTH - 1) {
            line[length] = (char)ch; //adding to a line
            length++; //counting chars to make sure it's not above length < MAX_LINE_LENGTH - 1
        }
    }

    return 0;
}
