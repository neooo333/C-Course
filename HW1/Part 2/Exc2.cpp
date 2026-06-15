#include <stdio.h>


int main (){

    int c;
    long int characters =0;
    long int words= 0;
    long int new_lines = 0;
    int in_word = 0;
    int first_iter = 0;

    printf ("Input text. Numbers of charachters, words and new lines will be counted \n");

    do {

        if (first_iter == 0) {
            first_iter++;
        }else{
          characters++;

        if (c == '\n'){ 
            new_lines++;
        };


        if (c == ' ' || c == '\t' || c == '\n') {
            in_word = 0; 
        } else {
            if (in_word == 0) {
                words++;
                in_word = 1; 
            }
        }
    }

    } while ((c = getchar ()) != 4 && c != EOF);


    printf ("Total Number of charachters: %ld \n", characters);
    printf ("Total Number of words: %ld \n", words);
    printf ("Total Number of new lines: %ld \n", new_lines);


    return 0;
};