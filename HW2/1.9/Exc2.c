// Echoes input lines to a file until CTRL+A (ASCII 1) is received
#include <stdio.h>

#define CTRL_A 1  /* ^A has ASCII value 1 */
#define MAX_FILE_NAME 100
#define MAX_LINE_LENGTH 1000

int main(void) {
    FILE *output_file;
    char file_name[MAX_FILE_NAME];
    char line[MAX_LINE_LENGTH];
    int ch;
    int length = 0;

    printf("Please enter the file name: ");
    scanf("%99s", file_name); //need to enter file name 

    output_file = fopen(file_name, "w"); // opean file in a writing mode
    if (output_file == NULL) { // the way to handle erros with accessing a file 
        printf("Could not open file.\n");
        return 1;
    }

    getchar();  //consume leftover newline after scanf

    // Buffer chars and write each completed line to the file 
    while ((ch = getchar()) != EOF) {
        if (ch == CTRL_A) { 
            fprintf(output_file, "CTRL + A is a correct ending.\n");
            fclose(output_file);
            return 0;
        }

        // Same idea as in the previos exc. 
        // Instead of printing of the screen we save chars to a file.
        if (ch == '\n') {
            for (int i = 0; i < length; i++) {
                fputc(line[i], output_file);
            }
            fputc('\n', output_file);
            length = 0;
        } else if (length < MAX_LINE_LENGTH - 1) { 
            line[length] = (char)ch; // adding to a line as a place to save chars 
            length++;
        }
    }

    fclose(output_file); // closing the file
    return 0;
}
