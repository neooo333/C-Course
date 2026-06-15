#include <stdio.h>

int main() {
    int c;
    long long total_chars = 0;
    long long total_words = 0;
    long long total_lines = 0;
    
    // Flag to keep track of whether we are inside a word
    // 0 = false (in whitespace), 1 = true (in a word)
    int in_word = 0; 

    printf("Enter text (Press CTRL+D to finish):\n");

    // Read character by character until EOF or the ASCII value 4 (^D) is encountered
    while ((c = getchar()) != EOF && c != 4) {
        total_chars++; // Every character typed counts

        // Check for newlines
        if (c == '\n') {
            total_lines++;
        }

        // Check for word boundaries (spaces, tabs, and newlines)
        if (c == ' ' || c == '\t' || c == '\n') {
            in_word = 0; // We hit a separator, so we are no longer in a word
        } else {
            // If it's a non-whitespace character and we weren't already in a word,
            // it means we just found the start of a new word.
            if (in_word == 0) {
                total_words++;
                in_word = 1; // Mark that we are now inside a word
            }
        }
    }

    // Print the final counts
    printf("\n--- Results ---\n");
    printf("Characters: %lld\n", total_chars);
    printf("Words:      %lld\n", total_words);
    printf("Newlines:   %lld\n", total_lines);

    return 0;
}
