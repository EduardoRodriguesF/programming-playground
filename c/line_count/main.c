#include <stdio.h>
int main() {
    char c;
    size_t n = 0;

    while ((c = getchar()) != EOF) if (c == '\n') n++;

    printf("%zu\n", n);
}
