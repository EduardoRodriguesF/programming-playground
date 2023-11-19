#include <stdio.h>

#define MAXLINE 1000
#define LENGTH_THRESHOLD 80

int m_getline(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
    int len, quantity;
    char line[MAXLINE];
    char matches[MAXLINE][MAXLINE];
    quantity = 0;

    while ((len = m_getline(line, MAXLINE)) > 0) {
        if (len > LENGTH_THRESHOLD) {
            copy(matches[quantity], line);
            quantity++;
        }
    }

    for (int i = 0; i < quantity; i++) {
        printf("%s", matches[i]);
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

void copy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') ++i;
}
