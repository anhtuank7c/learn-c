# Day 02 - Data Types & Variables

## Topics

- Basic data types: `int`, `float`, `double`, `char`
- Type modifiers: `short`, `long`, `signed`, `unsigned`
- `sizeof` operator
- Constants with `const` and `#define`
- Type limits (`limits.h`, `float.h`)

## Theory

```c
#include <stdio.h>
#include <limits.h>

int main()
{
    int a = 10;
    float b = 3.14f;
    double c = 3.141592654;
    char d = 'A';
    
    const float PI = 3.14f;
    printf("Size of int: %zu bytes\n", a);
    return 0;
}
```

| Type | Size (typical) | Range |
|----|----|----|
| char | 1 byte | -128 to 127 |
| int | 4 bytes | -2^31 to 2^31-1 |
| float | 4 bytes | ~6 decimal precision |
| double | 8 bytes | ~15 decimal precision |

## Excercises

- [x] Exercise 01: Declare variables of each basic type (`char`, `int`, `float`, `double`, `long`, `long long`) and print their sizes using `sizeof`.
- [x] Exercise 02: Read a temperature in Celsius and convert to Fahrenheit using the formula: `F = (C × 9/5) + 32`
- [x] Exercise 03: Calculate the area and circumference of a circle given its radius. Use `const` to define PI.
- [x] Exercise 04: Demonstrate integer overflow by multiplying large numbers. Print the result and observe the unexpected behavior.
- [x] Exercise 05: Read a character and print its ASCII value. Then read an ASCII value and print the corresponding character.
