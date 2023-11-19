#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

size_t m_getline(char line[], size_t maxline);
size_t count_char(char* string, char c);
char* detab(char string[], size_t length, size_t tabstop);

int main(int argc, char** argv) {
    char line[MAXLINE];
    size_t length, tabstop;

    tabstop = 4;

    if (argc > 1) {
        tabstop = atoi(argv[1]);
    }

    while ((length = m_getline(line, MAXLINE)) > 0) {
        printf("%s", detab(line, length, tabstop));
    }

    return 0;
}

size_t m_getline(char line[], size_t maxline) {
    int c, i;
    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) line[i] = c;

    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';

    return i;
}

size_t count_char(char* string, char c) {
    size_t n = 0;
    size_t length = strlen(string);

    for (int i = 0; i < length; i++) {
        if (string[i] == c) n++;
    }

    return n;
}

char *detab(char* string, size_t length, size_t tabstop) {
    size_t res_len = 0;
    size_t tabs_count = count_char(string, '\t');
    char *result = malloc(length + (tabs_count * tabstop));

    for (size_t i = 0; i < length; i++) {
        char c = string[i];

        if (c != '\t') {
            result[res_len++] = c;
            continue;
        }

        for (int j = 0; j < tabstop; j++) {
            result[res_len++] = ' ';
        }
    }

    result[res_len++] = '\0';

    return result;
}
