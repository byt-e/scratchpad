#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20

float fahr_to_celsius(float);
float celsius_to_fahr(float);

int main() {
    printf("%10s\t%10s\n", "Fahrenheit", "Celsius");
    float fahr;
    for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {
        printf("%10.0f\t%10.1f\n", fahr, fahr_to_celsius(fahr));
    }

    printf("%10s\t%10s\n", "-----", "-----");

    printf("%10s\t%10s\n", "Celsius", "Fahrenheit");
    float celsius;
    for (celsius = LOWER; celsius <= UPPER; celsius += STEP) {
        printf("%10.0f\t%10.1f\n", celsius, celsius_to_fahr(celsius));
    }

    return 0;
}

float fahr_to_celsius(float fahr)    { return 5 * (fahr-32) / 9; }
float celsius_to_fahr(float celsius) { return (celsius * 9/5) + 32; }
