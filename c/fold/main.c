#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

size_t m_getline(char line[], size_t maxline);
void fold_print(char *string, size_t length, size_t columns);

int main(int argc, char** argv) {
    char line[MAXLINE];
    size_t length, columns;

    columns = 40;

    if (argc > 1) {
        columns = atoi(argv[1]);
    }

    while ((length = m_getline(line, MAXLINE)) > 0) {
        fold_print(line, length, columns);
    }

    return 0;
}

int is_white_space(const char c) {
    return c == ' ' || c == '\t' || c == '\n';
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

void fold_print(char *string, size_t length, size_t columns) {
    char ch, word[length];
    size_t wlen, line_words, used_columns;
    used_columns = wlen = line_words = 0;

    for (size_t i = 0; i < length; i++) {
        ch = string[i];

        if (used_columns >= columns) {
            // break line
            if (line_words > 0) {
                putchar('\n');
                line_words = 0;
            }
            used_columns = strlen(word);
        }

        if (is_white_space(ch)) {
            printf("%s", word);
            line_words++;
            memset(word, 0, sizeof(word));
            wlen = 0;

            putchar(ch);
            used_columns++;
            continue;
        }

        if (wlen == columns - 1) {
            // fold this word to break line before column
            // threshold
            printf("%s-", word);
            line_words++;
            memset(word, 0, sizeof(word));
            wlen = 0;
        }

        word[wlen++] = ch;
        used_columns++;
    }

    if (ch != '\n') {
        putchar('\n');
    }
}
