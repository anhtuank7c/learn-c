# Day 01

Make a simple calculator application that receive 2 numbers from keyboard, then able to:

- Addition of two numbers
- Subtraction of two numbers
- Multiplication of two numbers
- Division of two numbers
- Modulus operation on two numbers
- Check if number is odd
- Check if number is even

## Project structure

```text
day_01/
    main.c          Entry point, invoke arithmetic operators from calculator.c, print out the result
    calculator.h    Header file containing function declaration for arithmetic operators
    calculator.c    Source file containing function definition for arithmetic operators
```

## Build & execution

```bash
cd day_01/

# Compile source code to single execution file
gcc -Wall -Wextra -o calculator main.c calculator.c

# execute program
./calculator
```
