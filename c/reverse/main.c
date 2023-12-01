#include <stdio.h>
#include <string.h>

void reverse(char str[]);

int main() {
    char message[] = "Hello";

    reverse(message);

    printf("%s", message);

    return 0;
}

void reverse(char str[]) {
    int i, j;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        char aux = str[i];
        str[i] = str[j];
        str[j] = aux;
    }
}
