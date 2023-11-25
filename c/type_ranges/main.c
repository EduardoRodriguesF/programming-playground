#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    printf("%18s %28s %28s\n", "Type", "Min", "Max");
    printf("%18s %28d %28d\n", "char", CHAR_MIN, CHAR_MAX);
    printf("%18s %28d %28u\n", "unsigned char", 0, UCHAR_MAX);

    printf("%18s %28d %28d\n", "int", INT_MIN, INT_MAX);
    printf("%18s %28d %28u\n", "unsigned int", 0, UINT_MAX);

    printf("%18s %28d %28d\n", "short", SHRT_MIN, SHRT_MAX);
    printf("%18s %28d %28u\n", "unsigned short", 0, USHRT_MAX);

    printf("%18s %28ld %28ld\n", "long", LONG_MIN, LONG_MAX);
    printf("%18s %28d %28lu\n", "unsigned long", 0, ULONG_MAX);

    printf("%18s %28lld %28lld\n", "long long", LONG_LONG_MIN, LONG_LONG_MAX);
    printf("%18s %28d %28llu\n", "unsigned long long", 0, ULONG_LONG_MAX);

    return 0;
}
