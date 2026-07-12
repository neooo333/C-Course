// Counts characters, words, and newlines from stdin (while loop)
#include <stdio.h>


int main (){

    int c;
    long int characters =0;
    long int words= 0;
    long int new_lines = 0;
    int in_word = 0;   // tracks whether we are currently inside a word

    printf ("Input text. Numbers of charachters, words and new lines will couted \n");

    while ((c = getchar ()) != 4 && c != EOF){

        characters++;

        if (c == '\n'){ 
            new_lines++;
        };


        // a word starts on the first non-blank char; blanks end it
        if (c == ' ' || c == '\t' || c == '\n') {
            in_word = 0; 
        } else {
            if (in_word == 0) {
                words++;
                in_word = 1; 
            }
        }
    }

    printf ("Total Number of charachters: %ld \n", characters);
    printf ("Total Number of words: %ld \n", words);
    printf ("Total Number of new lines: %ld \n", new_lines);


    return 0;
};