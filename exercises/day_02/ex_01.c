//
// Created by tuan-nguyen on 28/12/2025.
//
#include <stdio.h>

int main ()
{
    char a = 'A';
    printf("Size of char: %zu byte\n", sizeof(a));

    int b = 10;
    printf("Size of integer: %zu bytes\n", sizeof(b));

    float c = 3.14159;
    printf("Size of float: %zu bytes\n", sizeof(c));

    double d = 3.141592654;
    printf("Size of double: %zu bytes\n", sizeof(d));

    // combine with type modifiers
    printf("\n=== Combine with type modifiers ===\n");
    unsigned char e = 'e';
    printf("Size of unsigned char: %zu byte\n", sizeof(e));

    long i = 3.141592654;
    printf("Size of long: %zu bytes\n", sizeof(i));

    long int f = 3.14159;
    printf("Size of long int: %zu bytes\n", sizeof(f));
    unsigned long int ff = 3.141592654;
    printf("Size of unsigned long int: %zu bytes\n", sizeof(ff));

    long long int g = 3.14159;
    printf("Size of long long int: %zu bytes\n", sizeof(g));
    unsigned long long int gg = 3.141592654;
    printf("Size of unsigned long long int: %zu bytes\n", sizeof(gg));

    long double h = 3.141592654;
    printf("Size of long double: %zu bytes\n", sizeof(h));

    return 0;
}