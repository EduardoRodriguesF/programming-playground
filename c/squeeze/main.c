#include <stdio.h>
#include <stdbool.h>

void squeeze(char string[], const char exclude_charset[]);
bool includes(const char string[], const char ch);

int main() {
    char string[] = "Hello, world!";
    squeeze(string, "!eo ");

    printf("%s\n", string);

    return 0;
}

void squeeze(char string[], const char exclude_charset[]) {
    int i, j;

    for (i = j = 0; string[i] != '\0'; i++) {
        if (!includes(exclude_charset, string[i])) string[j++] = string[i];
    }

    string[j] = '\0';
}

bool includes(const char string[], const char ch) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == ch) return true;
    }

    return false;
}
