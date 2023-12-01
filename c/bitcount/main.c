#include <stddef.h>
#include <stdio.h>

size_t bitcount(unsigned x);

int main() {
    printf("%zu\n", bitcount(0b01001110));

    unsigned x = 0b01001110;
    printf("%u\n", x);
    printf("%u\n", x - 1);
    printf("%u\n", x & (x - 1));

    return 0;
}

size_t bitcount(unsigned x) {
    size_t n = 0;

    while (x != 0) {
        x &= (x - 1);
        n++;
    }

    return n;
}
