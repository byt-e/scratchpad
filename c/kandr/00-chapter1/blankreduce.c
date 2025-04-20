#include <stdio.h>

int main() {
    int c;
    int prev = 0;
    while ((c = getchar()) != EOF) {
        if (c != ' ') {
            prev = 0;
            putchar(c);
            continue;
        }

        if (prev == 1) {
            continue;
        }
        prev = 1;

        putchar(c);
    }

}
