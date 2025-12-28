//
// Created by tuan-nguyen on 28/12/2025.
//
#include <stdio.h>

#include "calculator.h"

int main()
{
    int a, b;
    printf("Enter two integers (separated by spacing): ");
    scanf("%d %d", &a, &b);
    printf("__________Result__________\n");
    printf("Addition: %d + %d = %d\n", a, b, add(a, b));
    printf("Subtraction: %d - %d = %f\n", a, b, divide(a, b));
    printf("Multiplication: %d * %d = %lld\n", a, b, multiply(a, b));
    printf("Division: %d / %d = %f\n", a, b, divide(a, b));
    printf("Is Odd: %d = %s\n", a, odd(a) ? "true" : "false");
    printf("Is Even: %d = %s\n", a, even(a) ? "true" : "false");

    printf("Modulus: %d modulus %d = %d\n", a, b, modulus(a, b));
    return 0;
}