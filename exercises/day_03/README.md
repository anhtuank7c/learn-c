# Day 03 - Operators

## Topics

- Arithmetic operators: `+ - * / %`
- Relational operators: `== >= <= > < !=`
- Logical operators: `&& || !`
- Bitwise operators: `& | ^ ~ << >>`
- Assignment operators: `= += -= *= /= %=`
- Ternary operator: `condition ? true_value : false value`
- Increment/Decrement: `++ --`

## Theory

```c
#include <stdio.h>

int main()
{
    // Arithmetic operators
    int sum = 10 + 20;      // 30
    int remainder = 10 % 3; // 1
    
    // Bitwise operators
    int a = 5;              // 0101 in binary
    int b = 3;              // 0011 in binary
    int and_result = a & b; // 0001 = 1
    int xor_result = a ^ b; // 0110 = 6
    
    // ternary operator
    int max = a > b ? a : b; // 5
    return 0;
}
```

## Exercises

- [ ] Exercise 01: Build a simple calculator that perform addition, subtraction, multiplication, division, and modulus. Read 2 numbers and operator from user.
- [ ] Exercise 02:
- [ ] Exercise 03:
- [ ] Exercise 04:
- [ ] Exercise 05: