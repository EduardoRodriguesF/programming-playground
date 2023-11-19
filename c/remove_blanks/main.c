#include <stdio.h>

#define MAXLINE 1000

int m_getline(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
    char line[MAXLINE];

    while (m_getline(line, MAXLINE) > 0) {
        printf("%s", line);
    }
}

int m_getline(char line[], int maxline) {
    int c, i;
    i = 0;
    while (i < maxline - 1 && (c = getchar()) != EOF && c != '\n') {
        if (c == ' ' || c == '\t') continue;

        line[i] = c;
        i++;
    }

    if (i > 0 && c == '\n') {
        line[i] = c;
        i++;
    }

    line[i] = '\0';

    return i;
}
