#include <stdio.h>

#define UPPER_LIMIT 300
#define LOWER_LIMIT 0
#define STEP 20

float to_celsius(float fahr);

int main() {
    float fahr, celsius;

    // Heading
    printf("%3c\t%6c\n", 'F', 'C');

    fahr = LOWER_LIMIT;
    while (fahr <= UPPER_LIMIT) {
        celsius = to_celsius(fahr);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr += STEP;
    }
}

float to_celsius(float fahr) {
    return 5.0f * (fahr - 32.0f) / 9.0f;
}
