#include <stddef.h>
#include <stdio.h>

unsigned rightrot(unsigned x, size_t n);

int main() {
    printf("%d\n", rightrot(0b011000, 12));

    return 0;
}

unsigned rightrot(unsigned x, size_t n) {
    unsigned leftmost_bit = 1 << sizeof(x);

    while (n-- > 0) {
        int lost_first_bit = x & 1;
        x >>= 1;

        if (lost_first_bit) {
            x |= leftmost_bit;
        }
    }

    return x;
}
