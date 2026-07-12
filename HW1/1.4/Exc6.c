// Counts how often digits 0–4 appear in the input text
#include <stdio.h>

int main() {
    int ch;

    int count0 = 0, count1 = 0, count2 = 0, count3 = 0, count4 = 0;
    int count_other = 0;

    printf("Enter text (Press Ctrl+Z followed by Enter on Windows, or Ctrl+D on Mac/Linux to trigger EOF):\n");

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

    printf("\n--- Character Frequencies ---\n");
    printf("0: %d\n", count0);
    printf("1: %d\n", count1);
    printf("2: %d\n", count2);
    printf("3: %d\n", count3);
    printf("4: %d\n", count4);
    printf("Other characters: %d\n", count_other);

    return 0;
}