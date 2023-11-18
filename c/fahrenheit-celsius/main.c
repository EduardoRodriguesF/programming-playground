#include <stdio.h>

#define UPPER_LIMIT 300
#define LOWER_LIMIT 0
#define STEP 20

int main() {
    float fahr, celsius;

    // Heading
    printf("%3c\t%6c\n", 'F', 'C');

    fahr = LOWER_LIMIT;
    while (fahr <= UPPER_LIMIT) {
        celsius = 5 * (fahr - 32) / 9;
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr += STEP;
    }
}
