//
// Created by tuan-nguyen on 28/12/2025.
//

#include "calculator.h"

#include <stdio.h>

int add(const int a, const int b)
{
    return a + b;
}

int subtract(const int a, const int b)
{
    return a - b;
}

long long multiply(const int a, const int b)
{
    return (long long)a * b;
}

double divide(const int a, const int b)
{
    if (b == 0)
    {
        fprintf(stderr, "Division by zero\n");
        return 0.0;
    }
    return (double)a / b;
}

bool even(const int a)
{
    return a % 2 == 0;
}

bool odd(const int a)
{
    // a & 1 is faster than a % 2 because bitwise operations are single CPU instructions, while modulus requires division.
    // Note: In binary, the last bit (LSB) represents the value 1 (which is 2⁰).
    // - Even numbers always have the last bit = 0
    // - Odd numbers always have the last bit = 1

    /**
     * Example 01
     *     a = 5 = 0101
     *       & 1 = 0001
     *-----------------
     *             0001 -> 1 (true, odd)
     *
     * Example 02
     *     a = 6 = 0110
     *       & 1 = 0001
     *-----------------
     *             0000 -> 0 (false, even)
     */
    return a & 1;
}

int modulus(const int a, const int b)
{
    if (b == 0)
    {
        fprintf(stderr, "Modulus by zero\n");
        return 0;
    }
    return a % b;
}
