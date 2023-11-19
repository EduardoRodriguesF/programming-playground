#include <stdio.h>

int main() {
    size_t n = 0;
    while (getchar() != EOF) ++n;

    printf("%1d\n", n);
}
