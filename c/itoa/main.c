#include <stdio.h>
#include <string.h>
void itoa(int n, char str[]);
void reverse(char str[]);

int main() {
    char str[32];

    itoa(-1092, str);

    printf("%s", str);
    return 0;
}

void itoa(int n, char str[]) {
    int sign = 1;
    if (n < 0) {
        sign = -1;
        n = -n;
    }

    int i = 0;
    do {
        str[i++] = n % 10 + '0';
    } while((n /= 10) > 0);

    if (sign < 0) str[i++] = '-';
    str[i] = '\0';

    reverse(str);
}

void reverse(char str[]) {
    int i, j;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        char aux = str[i];
        str[i] = str[j];
        str[j] = aux;
    }
}
