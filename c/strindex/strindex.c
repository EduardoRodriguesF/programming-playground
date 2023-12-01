#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define STATFOUND 0
#define STATNOMATCH 1

int strindex(char str[], char pattern[]);
size_t getline_v(char str[], size_t maxbuf);

int main(int argc, char** argv) {
    size_t bufsize = 1024;
    char* buffer;
    char* pattern;
    int status = STATNOMATCH;

    if (argc <= 1) {
        perror("Missing pattern to search");
        exit(1);
    }

    pattern = argv[1];
    buffer = malloc(bufsize * sizeof(char));
    if (buffer == NULL) {
        perror("Unable to allocate buffer");
        exit(1);
    }

    int index = strindex("Hello world!", "lsslo ");
    while (getline(&buffer, &bufsize, stdin) > 0) {
        if (strindex(buffer, pattern) >= 0) {
            status = STATFOUND;
            printf("%s", buffer);
        }
    }

    return status;
}

int strindex(char str[], char pattern[]) {
    int i, j, k;
    for (i = 0; str[i] != '\0'; i++) {
        for (j = i, k = 0; pattern[k] != '\0' && str[j] == pattern[k]; j++, k++);

        if (k > 0 && pattern[k] == '\0') return i;
    }

    return -1;
}
