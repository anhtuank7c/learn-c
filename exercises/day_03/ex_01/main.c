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
    printf("List operators: + - * / %%\n");
    printf("Please choose one arithmetic operator to perform: ");
    char operator;
    scanf(" %c", &operator);
    // printf("__________Result__________\n");
    switch (operator)
    {
    case '+':
        printf("Addition result: %d\n", add(a, b));
        break;
    case '-':
        printf("Subtraction result: %d\n", subtract(a, b));
        break;
    case '*':
        printf("Multiplication result: %lld\n", multiply(a, b));
        break;
    case '/':
        printf("Division result: %lf\n", divide(a, b));
        break;
    case '%':
        printf("Modulus result: %d\n", modulus(a, b));
        break;
    default:
        printf("Invalid operator\n");
    }
    // printf("Is Odd: %d = %s\n", a, odd(a) ? "true" : "false");
    // printf("Is Even: %d = %s\n", a, even(a) ? "true" : "false");

    // printf("Modulus: %d modulus %d = %d\n", a, b, modulus(a, b));
    return 0;
}
