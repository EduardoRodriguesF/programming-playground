#include <stdio.h>

int main() {
    char c;
    char last_c;

    while ((c = getchar()) != EOF) {
        if (c == ' ' && c == last_c) continue;

        last_c = c;
        putchar(c);
    }
}
