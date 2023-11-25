#include <stdio.h>

unsigned getbits(unsigned x, int position, int num);
unsigned setbits(unsigned x, int position, int num, unsigned y);
void print_bytes(const unsigned x);

int main() {
    print_bytes(140);
    print_bytes(getbits(0b10001100, 4, 3));
    print_bytes(getbits(0b11111101, 5, 3));

    int x = 0b10001100;
    int y = 0b10010101;
    printf("Setbits\n");
    printf("x: ");
    print_bytes(x);
    printf("y: ");
    print_bytes(y);

    printf("r: ");
    print_bytes(setbits(x, 12, 3, y));

    return 0;
}

unsigned getbits(unsigned x, int position, int num) {
    return (x >> (position + 1 - num)) & ~(~0 << num);
}

unsigned setbits(unsigned x, int position, int num, unsigned y) {
    unsigned rightmost = y & ~(~0 << num);
    unsigned ymask = rightmost << (position + 1 - num);

    return x | ymask;
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
