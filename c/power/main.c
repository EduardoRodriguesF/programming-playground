#include <stdio.h>
int power(int base, int n);

int main() {
    for (int i = 0; i < 10; i++) printf("%3d %3d %7d\n", i, power(2, i), power(-3, i));

    return 0;
}

int power(int base, int n) {
    int i, p;
    p = 1;

    for (i = 1; i <= n; ++i) p *= base;

    return p;
}
