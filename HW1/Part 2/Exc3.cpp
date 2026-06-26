// Same text statistics as Exc1, using switch statements
#include <stdio.h>


int main (){

    int c;
    long int characters =0;
    long int words= 0;
    long int new_lines = 0;
    int in_word = 0;

    printf ("Input text. Numbers of charachters, words and new lines will couted \n");

    while ((c = getchar ()) != 4 && c != EOF){

        characters++;

        switch (c){
            case '\n':
                new_lines++;
                break;
            default:
                break;
        }


        switch (c){
            case ' ':
                in_word = 0;
                break;
            case '\t':
                in_word = 0;
                break;
            case '\n':
                in_word = 0;
                break;
            default:
                switch (in_word) {
                    case 0:
                        words++;
                        in_word = 1; 
                        break;
                    default:
                        break;
                    }
                }
            }        

    printf ("Total Number of charachters: %ld \n", characters);
    printf ("Total Number of words: %ld \n", words);
    printf ("Total Number of new lines: %ld \n", new_lines);
    return 0;
}