#include <stdio.h>

#define IN 1
#define OUT 0
#define LENGTH 127

int main() {
    char c;
    size_t types[LENGTH];
    int state = OUT;

    for (int i = 0; i < LENGTH; i++) types[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') continue;
        types[c]++;
    }

    for (char i = 0; i < LENGTH; i++) {
        size_t n = types[i];
        if (n == 0) continue;

        printf("%3c ", i);
        for (int j = 0; j < n; j++) putchar('#');

        putchar('\n');
    }
}
