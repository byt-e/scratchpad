#include <stdio.h>

#define MAX_WORD_LENGTH 45

int main() {
    int word_lengths[MAX_WORD_LENGTH + 1] = {0}; // Longest english word is 45 characters

    int c;
    int word_length = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (word_length >= 0 && word_length <= 45) {
                ++word_lengths[word_length];
            }
            word_length = 0;
            continue;
        }

        word_length++;
    }

    if (word_length > 0 && word_length <= MAX_WORD_LENGTH) {
        ++word_lengths[word_length];
    }

    for (int i = 1; i <= MAX_WORD_LENGTH; i++) {
        if (word_lengths[i] <= 0) {
            continue;
        }

        printf("%2d: ", i);
        for (int j = 0; j < word_lengths[i]; j++) {
            putchar('*');
        }
        putchar('\n');
    }

    return 0;
}
