#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

char* to_lowercase(char* str) {
    char* result = malloc(strlen(str));

    char lower[] = "àáâäãç";
    char upper[] = "ÀÁÂÄÃÇ";

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            result[i] = str[i] + 32;
        } else {
            int found = 0;

            for (int j = 0; j < strlen(upper); j++) {
                if (upper[j] == str[i]) {
                    result[i] = lower[j];
                    found = 1;
                    break;
                }
            }

            if (!found) result[i] = str[i];
        }
    }

    return result;
}

int main() {
    char* s = "ç";
    printf("%d\n", '\xE7');
}
