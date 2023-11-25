#include <stdio.h>
#include <stdbool.h>

int any(const char string[], const char search[]);
bool includes(const char string[], const char ch);

int main() {
    char string[] = "Hello, world!";

    printf("%d\n", any(string, "world"));
    printf("%d\n", any(string, "!"));
    printf("%d\n", any(string, "He"));
    printf("%d\n", any(string, "zg"));

    return 0;
}

int any(const char string[], const char search[]) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (includes(search, string[i])) return i;
    }

    return -1;
}

bool includes(const char string[], const char ch) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == ch) return true;
    }

    return false;
}
