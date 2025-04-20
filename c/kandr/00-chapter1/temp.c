#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20

int main() {
    printf("%10s\t%10s\n", "Fahrenheit", "Celsius");
    float fahr;
    for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {
        float celsius = 5 * (fahr-32) / 9;
        printf("%10.0f\t%10.1f\n", fahr, celsius);
    }

    printf("%10s\t%10s\n", "-----", "-----");

    printf("%10s\t%10s\n", "Celsius", "Fahrenheit");
    float celsius;
    for (celsius = LOWER; celsius <= UPPER; celsius += STEP) {
        fahr = (celsius * 9/5) + 32;
        printf("%10.0f\t%10.1f\n", celsius, fahr);
    }

    return 0;
}
