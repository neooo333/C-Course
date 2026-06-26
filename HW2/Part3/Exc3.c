// Echoes input lines to a file until CTRL+A (ASCII 1) is received
#include <stdio.h>

#define CTRL_A 1
#define MAX_FILE_NAME 100
#define MAX_LINE_LENGTH 1000

int main(void) {
    FILE *output_file;
    char file_name[MAX_FILE_NAME];
    char line[MAX_LINE_LENGTH];
    int ch;
    int length = 0;

    printf("Please enter the file name: ");
    scanf("%99s", file_name);

    output_file = fopen(file_name, "w");
    if (output_file == NULL) {
        printf("Could not open file.\n");
        return 1;
    }

    getchar();

    while ((ch = getchar()) != EOF) {
        if (ch == CTRL_A) {
            fprintf(output_file, "CTRL + A is a correct ending.\n");
            fclose(output_file);
            return 0;
        }

        if (ch == '\n') {
            for (int i = 0; i < length; i++) {
                fputc(line[i], output_file);
            }
            fputc('\n', output_file);
            length = 0;
        } else if (length < MAX_LINE_LENGTH - 1) {
            line[length] = (char)ch;
            length++;
        }
    }

    fclose(output_file);

    return 0;
}
