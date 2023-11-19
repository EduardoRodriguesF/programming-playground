#include <stdio.h>

#define IN 1
#define OUT 0
#define LENGTH 128

int main() {
    char c;
    size_t n, lengths[128];
    int state = OUT;

    for (int i = 0; i < LENGTH; i++) lengths[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                lengths[n]++;
                n = 0;
            }

            state = OUT;
        } else {
            state = IN;
            n++;
        }
    }

    for (int i = 0; i < LENGTH; i++) {
        n = lengths[i];
        if (n == 0) continue;

        printf("%3d ", i);
        for (int j = 0; j < n; j++) putchar('#');

        putchar('\n');
    }
}
