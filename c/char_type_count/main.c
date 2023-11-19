#include <stdio.h>

#define NDIGIT_LENGTH 10

int is_white_space(char c) {
    return c == ' ' || c == '\n' || c == '\t';
}

int main() {
    int c, nwhite, nother;
    int ndigit[NDIGIT_LENGTH];

    for (int i = 0; i < NDIGIT_LENGTH; i++) ndigit[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') ndigit[c - '0']++;
        else if (is_white_space(c)) nwhite++;
        else nother++;
    }

    printf("digits =");
    for (int i = 0; i < NDIGIT_LENGTH; i++) {
        printf(" %d", ndigit[i]);
    }

    printf(", white space = %d, other = %d\n", nwhite, nother);
}
