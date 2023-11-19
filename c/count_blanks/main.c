#include <stddef.h>
#include <stdio.h>

int main() {
    char c;
    size_t n = 0;

    while ((c = getchar()) != EOF) {
        n += c == ' ' || c == '\n' || c == '\t' ;
    }

    printf("%zu", n);
}
