# Input & Output in C

Input & Output are fundamental operations in C programming that enable interaction between the program and the external world.

These operations allow a program to take user input (via the keyboard) and display results or messages (on the monitor or console).

## 1. **Input & Output steams**

- Input stream: Data flows from the input device (keyboard) to the program
- Output stream: Data flows from the program to the output device (monitor)

The input and output devices are relatively show compared to the CPU, necessitating the use of the buffers to manage the flow of data efficiently, avoiding character by character processing.

## 2. Streams in C

When a C program starts running, it interacts with three predefined streams:

* **stdin (Standard Input Stream)**: For input operations (keyboard)
* **stdout (Standard Output Stream)**: For output operations (monitor)
* **stderr (Standard Error Stream)**: For error messages

These streams are open and ready for use by default. The program writes or reads data in the form of characters or bytes, depending on the function being used.

## 3. Common Input & Output Functions in C

### 3.1 scanf

`scanf` is used for reading data from the standard input device. It is a general purpose function that can handle various data types like integers, float, characters, and strings. But it by default does not read strings with `spaces`

```c
// Example 1
short age;
char name[100];
float weight, height;
printf("What's your name?: ");
scanf("%s", name);
printf("How old are you?: ");
scanf("%d", &age);
printf("Enter your weight (kg): ");
scanf("%f", &weight);
printf("Enter your height (cm): ");
scanf("%f", &height);
const float bmi = (weight / height / height) * 10000;
printf("Hi %s\n", name);
printf("Your BMI at age %d is %.2f\n", age, bmi);

// Example 2
printf("\n\n");
int a, b;
printf("Now we're going to do additional operator, enter a and b:\n");
scanf("%d+%d", &a, &b);
printf("%d + %d = %d", a, b, a + b);
```



### 3.2 printf

`printf` is used for writing data to the standard output device. It can be used for displaying integers, float, characters and strings.

```c
printf("Hello world");

int age = 10, height = 140, weight = 20;
char name[] = "Sandeep";
printf("Hi %s,\nYour info:\nAge: %d, Height: %d, Weight: %d", name, age, height, weight);
```



### 3.3 fgets

`fgets` reads strings, including those with spaces, from the standard input or file streams. Originally designed for file input but can also be used for standard input.

Syntax: `fgets(name, len, stream);`

* name: Name of the string variable where the input string will be stored
* len: Length upto which the string is to be read
* stream: Input Stream, often **stdin (Standard Input)** for user input

In C, strings are null terminated, meaning an additional character (`\0`) is added to the end of the string. So `len` parameter should always the 1 + the desired size and it includes the space for the null terminator `\0`

```c
char name[100];
printf("Enter your name: \n");
fgets(name, 100, stdin);
printf("Your name is: %s\n", name);
printf("Welcome to C world");
```

### 3.4 puts

`puts` is used to write strings to the standard output device. It is simpler to use than printf for string outputs

### 3.5 getchar & putchar

* `getchar`: reads a single character from the standard input
* `putchar`: writes a single character to the standard output

### 3.6 getc & putc

Extended version of `getchar` and `putchar` that can operate on any stream (e.g files or stdin/stdout)

## 4. File stream vs Standard Stream

C uses the same syntax for reading from and writing to files as it does for standard input/output operations.

By providing a file stream instead of stdin or stdout, functions like `fgets`, `fputs`, `getc`and `putc` can seemlessly work with files.

## 5. Error steam (stderr)

The `stderr` stream is used for error messages. It is unbuffered, meaning messages are displayed immediately without for the buffer to fill

## 6. Format specifier for Integers in C

In C, format specifiers are used in functions like **printf** and **scanf** to read and write data.

They are used as a placeholder in the format string for input and output with **printf**, **scanf** and similar functions.

There are 8 integer format specifiers in C:

| Format specifier | Data Type                  | Description                                                  |
| ---------------- | -------------------------- | ------------------------------------------------------------ |
| `%d`             | Signed Integer             | Used for printing or reading signed integers, supporting both positive and negative values. |
| `%u`             | Unsigned Integer           | Used for storing only positive numbers or zero, effectively doubling the integer range |
| `%ld`            | Long Integer               | Used for larger integers when normal integers can't hold the required value. |
| `%lld`           | Long Long Integer          | Used for even larger integers, offering a wider range than `%ld` |
| `%zd`            | Size of Data Type          | Used for printing size_t values, typically representing the size of objects or arrays. |
| `%x` or `%X`     | Hexadecimal Representation | Prints integers in hexadecimal format: `%x` for lowercase (a-f) and `%X` for uppercase (A-F). |
| `%o`             | Octal Representation       | Prints integers in octal (base 8) format, with an optional prefix (e.g., 012). |
| `%i`             | Integer Input              | Similar to `%d` but can read decimal, octal, and hexadecimal numbers. If input starts with `0x` or `0`, it is treated accordingly. |

Example

```c
int x = 9;
printf("\nx = %d", x);

unsigned int x2 = 0;
printf("\nx2 = %u", x2);

long y = -200;
printf("\ny = %ld", y);

long long z = 300;
printf("\ny = %lld", z);

printf("\nSize of Z = %zd", sizeof(z)); // Size of Z = 8

printf("\n%0x", 0x123abc); // 123abc
printf("\n%0X", 0x123abc); // 123ABC
printf("\n%o", 01234567); // 1234567
```

## 7. Format specifiers for floating point number

In C, floating point numbers are represented using the **float**, **double** and **long double** data types. When it comes to printing these floating point values, we have 3 main format specifiers: **`%f`**, **`%e`**, **`%g`**

### 7.1 `%f`: Fixed point notation

The `%f` format specifier is used to print floating-point numbers in fixed-point notation. This format ensures a fixed number of digits after the decimal point.

* By default `%f` prints 6 digits after the decimal point
* If you enter a number with fewer digits after the decimal point, the remaining spaces are filled with zeros
* If more than 6 digits are provided, the extra digits are rounded off, and only the first 6 digits are printed

In the case of `long double` values, the format specifier becomes `%Lf` for fixed point representation

```c
#include <stdio.h>

int main(void) {
    float x = 10.25f;
    double y = 123.123456789;
    double z = 15e+8;
    printf("%f  %f  %f", x, y, z);
    return 0;
}
// 10.250000  123.123457  1500000000.000000
```

### 7.2 `%e`: Exponential Notation

The `%e` format specifier is used to print numbers in exponential (scientific) notation. In this notation, numbers are represented in the form: `1.2 * (10^24)`, `-2.11 * (10^-11)`

* The output is always printed with one digit before the decimal and 6 digits after it
* The exponent is always printed with at least 2 digits, including a leading zero if necessary

The `%e` notation is used for every large or very small numbers, making them easier to read and understand

Example

```c
#include <stdio.h>

int main(void) {
    float x = 10.25f;
    double y = 123.123456789;
    double z = 15e+8;
    printf("%e  %e  %e", x, y, z);
    return 0;
}
// 1.025000e+01  1.231235e+02  1.500000e+09
```

### 7.3 `%g`: Mixed Notation

The `%g` format specifier is a mix between `%f` and `%e`. It choose the most compact representation between fixed point and exponential notation based on the value of the floating point number

* If the number is very small or very large, `%g` will switch to exponential notation
* Otherwise, it will print in fixed point notation
* `%g` ensures that the total number of digits printed (before and after the decimal) does not exceed 6
* It eliminates trailing zeros in the fixed point representation

```c
#include <stdio.h>

int main(void) {
    float x = 10.25f;
    double y = 123.123456789;
    double z = 15e+8;
    printf("%g  %g  %g", x, y, z);
    return 0;
}
// 10.25  123.123  1.5e+09
```

**Important points**

* When printing floating point numbers, C automatically converts float values to double for output. This means that the format specifiers `%f`, `%g`, `%e` are used primarily for double values
* For `long double` numbers, you need to use `%Lf`, `%Le` and `%Lg` 

## 8. Other Format specifiers in C

| Specifier | Data Type                    | Description                                                  |
| --------- | ---------------------------- | ------------------------------------------------------------ |
| `%c`      | Character                    | Used for printing or scanning a single character. It reads or writes a single character from a given variable |
| `%s`      | String                       | Used for printing or scanning strings. A string is a sequence of characters terminated by a special null character `\0`. This format specifier reads or writes strings form or to variables |
| `%p`      | Pointer                      | Used for printing memory addresses or pointers. In C, pointers are variables that store memory addresses of other variables. To obtain the memory address of a variable, we use the address of operator `&` |
| `%n`      | Number of characters printed | The `%n` format specifier is unique because it is not used to print any values. Instead, it is used to store the number of characters printed so far by the `printf` function into an integer variable. |

```c
#include <stdio.h>
int main()
{
    int a = 'g';
    char b[] = "gfg";
    printf("%c %s %p", a, b, &a); // g gfg 0x7ffec6a2fb5f
  
 		int x;
    printf("abc %n cd \n", &x); // abc  cd 
    printf("The value of x is %d", x); // The value of x is 4
  
    return 0;
}
```

