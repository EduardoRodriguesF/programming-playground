#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

int m_getline(char line[], int maxline);
char* reverse(char string[], size_t length);

int main() {
    size_t len;
    char line[MAXLINE];

    while ((len = m_getline(line, MAXLINE)) > 0) {
        printf("%s", reverse(line, len));
    }
}

int m_getline(char line[], int maxline) {
    int c, i;
    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) line[i] = c;

    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';

    return i;
}

char* reverse(char string[], size_t length) {
    char* reversed = malloc(length);
    int i, j;

    i = 0;
    for (int j = length - 1; j > 0; j--) {
        reversed[i] = string[j];
        i++;
    }

    return reversed;
}
