#include <stdio.h>
int htoi(const char* str);

int main() {

    printf("11: %d\n", htoi("11"));
    printf("1300: %d\n", htoi("1300"));
    printf("FE1A: %d\n", htoi("FE1A"));
    printf("fE1a: %D\n", htoi("fE1a"));

    printf("0x11: %d\n", htoi("0x11"));
    printf("0x1300: %d\n", htoi("0x1300"));
    printf("0XFE1A: %d\n", htoi("0XFE1A"));
    printf("0xfE1a: %D\n", htoi("0xfE1a"));

    return 0;
}

int htoi(const char* str) {
    int i, n;
    char ch;
    i = n = 0;

    while ((ch = str[i]) != '\0') {
        int digit = 0;

        if (ch >= '0' && str[i] <= '9') {
            digit = ch - '0';
        } else if (ch >= 'a' && str[i] <= 'f') {
            digit = ch - 'a' + 10;
        } else if (ch >= 'A' && str[i] <= 'F') {
            digit = ch - 'A' + 10;
        }

        n = (n << 4) + digit;
        i++;
    }

    return n;
}
