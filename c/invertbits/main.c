#include <stdio.h>

unsigned invertbits(unsigned x, int position, int num);
void print_bytes(const unsigned x);

int main() {
    print_bytes(140);
    printf("\n");
    print_bytes(140);
    print_bytes(invertbits(140, 5, 3));

    return 0;
}

unsigned invertbits(unsigned x, int position, int num) {
    unsigned mask = ~(~0 << num) << (position + 1 - num);
    return x ^ mask;
}

void print_bytes(const unsigned x) {
    unsigned ref = x;
    unsigned bits = sizeof(x) * 8;
    unsigned mask = ~0 << (bits - 1);

    for (int i = bits; i > 0; i--) {
        unsigned r = ref & mask;
        printf("%d", r > 0 ? 1 : 0);

        ref = (ref << 1);
    }
    
    printf("\n");
}
