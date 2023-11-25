#include <stddef.h>
#include <stdio.h>

size_t bitcount(unsigned x);

int main() {
    printf("%zu\n", bitcount(0b01001110));

    return 0;
}

size_t bitcount(unsigned x) {
    size_t n;
    for (n = 0; x != 0; x >>= 1) {
        n += x & 01;
    }

    return n;
}
