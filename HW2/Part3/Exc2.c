// Echoes input lines to stdout until CTRL+A (ASCII 1) is received
#include <stdio.h>

#define CTRL_A 1
#define MAX_LINE_LENGTH 1000

int main(void) {
    int ch;
    char line[MAX_LINE_LENGTH];
    int length = 0;

    while ((ch = getchar()) != EOF) {
        if (ch == CTRL_A) {
            printf("CTRL + A is a correct ending.\n");
            return 0;
        }

        if (ch == '\n') {
            for (int i = 0; i < length; i++) {
                putchar(line[i]);
            }
            putchar('\n');
            length = 0;
        } else if (length < MAX_LINE_LENGTH - 1) {
            line[length] = (char)ch;
            length++;
        }
    }

    return 0;
}
