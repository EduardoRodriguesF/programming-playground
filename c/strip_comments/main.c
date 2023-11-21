#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXBUF 1024

enum State {
    Out,
    String,
    MaybeComment, // First / found.
    MultilineComment, // Definetly a multiline comment. * found after MaybeCommand's /.
    ClosingMultilineComment, // Found * inside comment. If / is found next, Out.
};

// Returns line length
size_t get_line(char line[], size_t maxbuf);

int main() {
    size_t length;
    char line[MAXBUF];
    enum State state = Out;

    while ((length = get_line(line, MAXBUF)) > 0) {
        char *result = malloc(length);
        size_t rlength = 0;
        size_t total_nonblanks = 0;
        bool has_comment = false;

        for (size_t i = 0; i < length; i++) {
            char ch = line[i];

            if (state == Out) {
                if (ch == '/') state = MaybeComment;
                result[rlength++] = ch;

                total_nonblanks += !isblank(ch) && ch != '\n'; // line is more than just comment.
                if (ch == '"') state = String;

                continue;
            }

            if (state == MaybeComment) {
                if (ch == '/') {
                    state = Out;

                    total_nonblanks--; // Previously added '/' will be removed
                    has_comment = true;

                    char fill = '\0';
                    if (total_nonblanks > 0) fill = '\n';

                    result[rlength - 1] = fill;
                    break; // There is no more content to look for. Time to return line.
                } else if (ch == '*') {
                    state = MultilineComment;
                    has_comment = true;
                    total_nonblanks--; // Previously added '/' will be removed

                    char fill = '\0';
                    if (total_nonblanks > 0) fill = '\n';

                    result[rlength - 1] = fill;
                } else {
                    state = Out;
                    result[rlength++] = ch;
                    total_nonblanks += !isblank(ch) && ch != '\n';
                }

                continue;
            }

            if (state == MultilineComment) {
                has_comment = true;
                if (ch == '*') state = ClosingMultilineComment;
                continue;
            }

            if (state == ClosingMultilineComment) {
                if (ch == '/') state = Out;
                else state = MultilineComment; // Failed to close
                continue;
            }

            if (state == String) {
                result[rlength++] = ch;
                total_nonblanks += !isblank(ch) && ch != '\n';

                if (ch == '"') state = Out;

                continue;
            }
        }

        if (has_comment && total_nonblanks == 0) continue;

        printf("%s", result);
    }

    return 0;
}

size_t get_line(char line[], size_t maxbuf) {
    int c, i;
    for (i = 0; i < maxbuf - 1 && (c = getchar()) != EOF && c != '\n'; i++) line[i] = c;

    if (c == '\n') {
        line[i++] = c;
    }

    line[i] = '\0';

    return i;
}
