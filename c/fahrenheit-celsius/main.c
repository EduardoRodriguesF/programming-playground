#include <stdio.h>

#define UPPER_LIMIT 300
#define LOWER_LIMIT 0
#define STEP 20


int main() {
    int fahr, celsius;

    fahr = LOWER_LIMIT;
    while (fahr <= UPPER_LIMIT) {
        celsius = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr += STEP;
    }
}
