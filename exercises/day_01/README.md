# Day 01 - Setup & First Program

## Topics

- Environment setup (gcc, ide/editor)
- Compilation process (gcc, clang)
- `printf` for output
- `scanf` for input
- Basic program structure

## Theory

```c
#include <stdio.h> // header for input/output

int main() // entry point
{
    // your code here
    return 0; // Exit status
}
```

Compilation:

```c
// compile
gcc -o program_name entry_file.c another_related_file.c and_another_file.c

// execute program
./program_name
```

## Exercises

- [x] Exercise 01: Install a C compiler (gcc) and write a program that prints "Hello, World!" to the console
- [x] Exercise 02: Print your name, age, and favorite programming language on separate lines.
- [x] Exercise 03: Read two integers from user input and print their sum.
- [x] Exercise 04: Print the following pattern using `printf`
    ```
    *
    **
    ***
    ****
    *****
    ```
- [x] Exercise 05: Read the user's name and print a personalized greeting message.
