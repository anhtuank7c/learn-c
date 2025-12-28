//
// Created by tuan-nguyen on 28/12/2025.
//
#include <stdio.h>

float convert_celsius_to_fahrenheit(float celsius);

int main()
{
    float temperature_celsius;
    printf("Enter temperature in Celsius to convert to Fahrenheit: ");
    scanf("%f", &temperature_celsius);
    float temperature_fahrenheit = convert_celsius_to_fahrenheit(temperature_celsius);
    printf("%.0fC = %.2fF\n", temperature_celsius, temperature_fahrenheit);
    return 0;
}

float convert_celsius_to_fahrenheit(float celsius)
{
    return (float) (celsius * 9/5) + 32;
}