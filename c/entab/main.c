#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

size_t m_getline(char line[], size_t maxline);
char* entab(char string[], size_t length, size_t tabstop);

int main(int argc, char** argv) {
    char line[MAXLINE];
    size_t length, tabstop;

    tabstop = 4;

    if (argc > 1) {
        tabstop = atoi(argv[1]);
    }

    while ((length = m_getline(line, MAXLINE)) > 0) {
        printf("%s", entab(line, length, tabstop));
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

char *entab(char* string, size_t length, size_t tabstop) {
    size_t res_len = 0;
    char *result = malloc(length);

    for (size_t i = 0; i < length; i++) {
        char c = string[i];

        if (c != ' ') {
            result[res_len++] = c;
            continue;
        }

        size_t blank_count; 
        for (blank_count = 0; string[i + blank_count] == ' '; blank_count++);

        i += blank_count - 1;

        while (blank_count > 0) {
            if (blank_count >= tabstop) {
                result[res_len++] = '\t';
                blank_count -= tabstop;
                continue;
            }

            result[res_len++] = ' ';
            blank_count--;
        }
    }

    result[res_len++] = '\0';

    return result;
}
