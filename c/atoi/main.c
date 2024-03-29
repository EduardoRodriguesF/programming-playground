#include <stdio.h>
#include <ctype.h>

int atoi(char str[]);

int main() {
    printf("%d\n", atoi("1"));
    printf("%d\n", atoi("53234"));
    printf("%d\n", atoi("0099900"));

    return 0;
}

int atoi(char str[]) {
    int i, n, sign;

    for (i = 0; isspace(str[i]); i++); // Skip

    sign = (str[i] == '-') ? -1 : 1;
    if (str[i] == '+' || str[i] == '-') i++;

    for (n = 0; isdigit(str[i]); i++) n = 10 * n + (str[i] - '0');

    return sign * n;
}
