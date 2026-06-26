// Counts digit frequencies with extra output for the digit 3
#include <stdio.h>

int main() {
    int ch;
    
    // Initialize counters for numbers 0-4 and other characters
    int count0 = 0, count1 = 0, count2 = 0, count3 = 0, count4 = 0;
    int count_other = 0;

    printf("Enter text (Press Ctrl+Z followed by Enter on Windows, or Ctrl+D on Mac/Linux to trigger EOF):\n");

    // Read character by character until EOF
    while ((ch = getchar()) != EOF) {
        switch (ch) {
            case '0':
                count0++;
                break;
            case '1':
                count1++;
                break;
            case '2':
                count2++;
                break;
            case '3':
                count3++;
                break;
            case '4':
                count4++;
                break;
            default:
                count_other++;
                break;
        }
    }

    // Print the final frequencies
    printf("\n--- Character Frequencies ---\n");
    printf("0: %d\n", count0);
    printf("1: %d\n", count1);
    printf("2: %d\n", count2);

    // Extended logic for the number 3
    if (count3 < 3) {
        switch (count3) {
            case 0:
                printf("Number three appears zero times.\n");
                break;
            case 1:
                printf("Number three appears one time.\n");
                break;
            case 2:
                printf("Number three appears two times.\n");
                break;
        }
    } else {
        printf("The number three appears more than two times.\n");
    }

    printf("4: %d\n", count4);
    printf("Other characters: %d\n", count_other);

    return 0;
}