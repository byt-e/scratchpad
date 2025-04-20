#include <stdio.h>

#define MAX_WORD_LENGTH 45
#define HISTOGRAM_WIDTH 15  // Limit display width for clarity

int main() {
    int word_lengths[MAX_WORD_LENGTH] = {0};

    int c;
    int word_length = 0;

    // Count word lengths
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (word_length > 0 && word_length <= MAX_WORD_LENGTH) {
                ++word_lengths[word_length - 1];
            }
            word_length = 0;
        } else {
            ++word_length;
        }
    }

    // Handle final word (if not newline-terminated)
    if (word_length > 0 && word_length <= MAX_WORD_LENGTH) {
        ++word_lengths[word_length - 1];
    }

    // Horizontal histogram
    printf("\nHorizontal Histogram\n--------------------\n");
    for (int i = 0; i < MAX_WORD_LENGTH && i < HISTOGRAM_WIDTH; i++) {
        if (word_lengths[i] > 0) {
            printf("%2d: ", i + 1);
            for (int j = 0; j < word_lengths[i]; j++) {
                putchar('*');
            }
            putchar('\n');
        }
    }

    // Find max for vertical height
    int max = 0;
    for (int i = 0; i < MAX_WORD_LENGTH; ++i) {
        if (word_lengths[i] > max) {
            max = word_lengths[i];
        }
    }

    // Vertical histogram
    printf("\nVertical Histogram\n--------------------\n");
    for (int row = max; row > 0; --row) {
        for (int col = 0; col < MAX_WORD_LENGTH && col < HISTOGRAM_WIDTH; ++col) {
            if (word_lengths[col] > 0) {
                if (word_lengths[col] >= row) {
                    printf(" * ");
                } else {
                    printf("   ");
                }
            }
        }
        putchar('\n');
    }

    // Footer (word lengths)
    for (int col = 0; col < MAX_WORD_LENGTH && col < HISTOGRAM_WIDTH; ++col) {
        if (word_lengths[col] > 0) {
            printf("%2d ", col + 1);
        }
    }
    putchar('\n');

    return 0;
}

