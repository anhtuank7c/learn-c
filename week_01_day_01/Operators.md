# Operators

Operators are the foundation of any programming language.

Thus the functionality of C language is incomplete without the use of operators. Operators allow us to perform different kinds of operations on operands.

In C, operators can be categorized in following categories:

* Arithmetic operators: `+`, `-`, `*`, `/`, `%`, post-increment, pre-increment, post-decrement, pre-decrement
* Relational operators: `==`, `!=`, `>`, `<`, `>=`, `<=`
* Logical operators: `&&`, `||`, `!`
* Bitwise operators: `&`, `|`, `^`, `~`, `>>`, `<<`
* Assignment operators: `=`, `+=`, `-=`, `*=`, etc...
* Other operators: conditional, comma, sizeof, address, redirection

| Name             | Type                              | Operator                        |
| ---------------- | --------------------------------- | ------------------------------- |
| Unary operator   | `++`, `--`                        | Unary operator                  |
| Binary operator  | `+`, `-`, `*`, `/`, `%`           | Arithmetic operator             |
|                  | `==`, `!=`, `>`, `<`, `>=`, `<=`  | Relational operator             |
|                  | `&&`, `||`, `!`                   | Logical operator                |
|                  | `&`, `|`, `^`, `~`, `>>`, `<<`    | Bitwise operator                |
|                  | `=`, `+=`, `-=`, `*=`, `/=`, `%=` | Assignment operator             |
| Ternary operator | `?:`                              | Ternary or conditional operator |

## 1. Arithmetic operators

Arithmetic operators are used to perform operations on operands.

There are 2 types of arithmetic operators:

* Binary
* Unary

### 1.1 Binary operators

There are 5 binary operators such as `+`, `-`, `*`, `/`, `%`

**Addition operator (`+`**)

The `+` operator adds two operands ` 20 + 30 = 50 `

**Subtraction operator (`-`**)

The `-` operator subtracts two operands `30 - 20 = 10`

**Multiplication operator (`*`**)

The `*` operator multiplies two operands `20 * 10 = 200`

**Division operator (`/`**)

The `/` operator divides the first operand by the second. If both operands are integers, the result is truncated to an integer.

```c
8 / 3 = 2.667 // for integers
8.0 / 3.0 = 2.667 // for floating point numbers
```

**Modulus operator (`%`**)

The `%` operator returns the remainder when the first operand is divided by the second

```c
8 % 3 = 2;
```

The sign of the result depends on the sign of the first operand

```c
8 % -3 = 2;
-8 % 3 = -2;
```

Division `/` and remainder `%` operations are undefined when the divisor is zero.

* For integer division: results in a runtime error in most compiler (e.g GCC)
* For floating point division: produces special values such as `INF` (positive infinity) or `-INF` (negative infinity)

### 1.2 Unary operators

Unary arithmetic operators perform operation on a single operand. Among these, the most commonly used operators are postfix `++`, `--` and prefix increment and decrement operators.

**Increment operator (`++`**)

The `++` operator is used to increment the value of an integer by one.

* When placed before the variable name (pre-increment) its value is incremented instantly.

  ```c
  int x = 10;
  int y = ++x; // pre-increment
  printf("x = %d, y = %d\n", x, y); // x = 11, y = 11
  
  // value of x incremented instantly from 10 to 11
  // then assign 11 to y
  ```

* When placed after the variable name (post-increment) its value is incremented after the evaluation of whole expression

  ```c
  int x = 10;
  int z = x++; // post-increment
  printf("x = %d, z = %d\n", x, z); // x = 11, z = 10
  
  // old value of x (10) assigned to z, then x incremented by 1 (result: x = 11)
  ```

**Decrement operator (`--`**)

The `--` operator is used to decrement the value of an integer by one.

* When placed before the variable name (pre-decrement) its value is decremented instantly

  ```c
  int x = 10;
  int y = --x; // pre-decrement
  printf("x = %d, y = %d\n", x, y); // x = 9, y = 9
  
  // value of x decremented instantly from 10 to 9
  // then assign 9 to y
  ```

* When placed after the variable name (post-decrement) its value is decremented after the evaluation of whole expression

  ```c
  int x = 10;
  int z = x--; // post-decrement
  printf("x = %d, z = %d\n", x, z); // x = 9, z = 10
  
  // old value of x (10) assigned to z, then x decremented by 1 (result: x = 9)
  ```

## 2. Comparison operators

Comparison operators are fundamental tools used to compare two values. They evaluate expressions and return Boolean value (true/false) which are represented as `1` for true, and `0` for false.

There are 6 comparison operators in C:

### 2.1 Less than (`<`)

```c
#include <stdbool.h>

const bool is_less_than = 10 < 20; // true
printf("%d", is_less_than); // 1
```

### 2.2 Greater than (`>`)

```c
#include <stdbool.h>

const bool is_less_than = 10 > 20; // false
printf("%d", is_less_than); // 0
```

### 2.3 Less than or equal to (`<=`)

```c
#include <stdbool.h>

const bool is_less_than = 10 <= 20; // true
const bool is_less_than_equal = 20 <= 20; // true
printf("%d %d", is_less_than, is_less_than_equal); // 1 1
```

### 2.4 Greater than or equal to (`>=`)

```c
#include <stdbool.h>

const bool is_less_than = 10 >= 20; // false
const bool is_less_than_equal = 20 >= 20; // true
printf("%d %d", is_less_than, is_less_than_equal); // 0 1
```

### 2.5 Equal to (`==`)

```c
#include <stdbool.h>

const bool is_equal = 10 == 20; // false
const bool is_equal_two = 20 == 20; // true
printf("%d %d", is_equal, is_equal_two); // 0 1
```

### 2.6 Not equal to (`!=`)

```c
#include <stdbool.h>

const bool is_not_equal = 10 != 20; // true
const bool is_not_equal_two = 20 == 20; // false
printf("%d %d", is_not_equal, is_not_equal_two); // 1 0
```

## 3. Assignment operators

Assignment operators are used to assign the value of a variable.

### 3.1 Simple Assignment Operator (`=`)

A simple assigment operator `=` is used to assign the value to a variable

```c
int x = 10; // assign 10 to x
int y = -200; // assign -200 to y
```

### 3.2 Compound Assignment Operators

These operators are used to calculate basic mathematical calculations and assign them to the variable.

They are shorthand notations that improve code readability and reduce redundancy.

* Addition and assign `+=`
* Subtraction and assign `-=`
* Multiplication and assign `*=`
* Division and assign `/=`
* Remainder and assign `%=`

Example

```c
int x = 10, y;
y = x; // y = 10
y += x; // y = 10, x = 10; 10 + 10 = 20; y = 20;
y -= x; // y = 10
y *= x; // y = 10, x = 10; 10 * 10 = 100; y = 100;
y /= x; // y = 100, x = 10; 100 / 10 = 10; y = 10;
```

## 4. Logical operators

Logical operators take boolean inputs and produce boolean output.

They're commonly used with comparison operators to form more complex expressions.

Categorized into two parts:

* Unary: we have only one logical operator in this category
* Binary: we have logical `AND` and `OR` operators in this category

### 4.1 AND operator (`&&`)

The `&&` operator returns true when both conditions are true, otherwise it returns false.

**Truth table**

| Operand 1 | Operand 2 | `&&` |
| --------- | --------- | ---- |
| 0         | 0         | 0    |
| 1         | 0         | 0    |
| 0         | 1         | 0    |
| 1         | 1         | 1    |

### 4.2 OR operator (`||`)

The `||` operator returns true even if one (or both) of the conditions are true, otherwise it returns false.

**Truth table**

| Operand 1 | Operand 2 | `||` |
| --------- | --------- | ---- |
| 0         | 0         | 0    |
| 1         | 0         | 1    |
| 0         | 1         | 1    |
| 1         | 1         | 1    |

### 4.3 NOT operator (`!`)

The `!` operator returns true if the conditions is not true, otherwise it returns false.

**Truth table**

| Operand | `!`  |
| ------- | ---- |
| 0       | 1    |
| 1       | 0    |

### 4.4 Short-circuiting in Logical Operators

Short-circuiting refers to the behavior of logical operators where evaluation stops as soon as the result is determined. In the case of logical AND, the second expression/condition is not evaluated if the first expression/condition is false. and in logical OR, second expression/condition is not evaluated if the first condition is true.

**Example 1**

```c
int x = 5;
bool result = (x > 10 && x++);
printf("%d %d\n", result, x); // 0 5

// because x is not greater than 10 (false)
// then x++ will be ignore (not being evaludate since the first condition is false)
```

**Example 2**

```c
int x = 5;
bool result = (x++ && x > 10);
printf("%d %d\n", result, x); // 0 6

// Step 1:
// x++ return 5 because this is post-increment
// then it incremented by 1 so we have 6
// in binary representation any integer that is not 0 is true
// so x++ return 5 will be consider as true

// Step 2:
// since the left operand is true, now evaluate the right operand x > 10
// x is now 6
// 6 < 10 so operand x > 10 is false (or 0)

// Step 3:
// combine with AND operator we have
// 5 (true) && 0

// so result = 0
// x incremented to 6
```

**Example 3**

```c
int x = 5;
bool result = (x > 2 || x++);
printf("%d %d", result, x); // 1 5

// Step 1:
// x > 2 return true (or 1)

// Step 2:
// OR operator just need one operand to being true, it will not evaluate the second operand
// so x++ will be ignored
```

## 5. Bitwise operators

Bitwise operators work on the binary representation of integers, operating bit by bit to perform logical operations.

These operators are incredibly faster than arithmetic and other operators.

There are a total 6 bitwise operators in C.

### 5.1 Bitwise AND (`&`)

Bitwise `AND` operator takes two numbers as operands and does `AND` on every bit of two numbers.

The result of `AND` is `1` only if both bits are 1, otherwise the result is `0`

```c
int x = 3, y = 6;
int result = x & y; // 2

// 0011 & 0110 = 0010 (2 in decimal)
```

| Operand | Binary  | Operator     |
| ------- | ------- | ------------ |
| 3       | 0 0 1 1 | &            |
| 6       | 0 1 1 0 |              |
| Result  | 0 0 1 0 | 2 in decimal |

### 5.2 Bitwise OR (`|`)

Bitwise `OR` operator takes two numbers as operands and does `OR` on every bit of two numbers.

The result of `OR` is `1` if any one of them is `1`

```c
int x = 3, y = 6;
int result = x | y;

// 0011 | 0110 = 0111 (7 in decimal)
```

| Operand | Binary  | Operator     |
| ------- | ------- | ------------ |
| 3       | 0 0 1 1 | \|           |
| 6       | 0 1 1 0 |              |
| Result  | 0 1 1 1 | 7 in decimal |

### 5.3 Bitwise XOR (`^`)

Bitwise `XOR` operator takes two numbers as operands and does `XOR` on every bit of two numbers.

The result of `XOR` is `1` if two bits are different, otherwise the result is `0`

```c
int x = 3, y = 6;
int result = x ^ y;

// 0011 ^ 0110 = 0101 (5 in decimal)
```

| Operand | Binary  | Operator     |
| ------- | ------- | ------------ |
| 3       | 0 0 1 1 | ^            |
| 6       | 0 1 1 0 |              |
| Result  | 0 1 0 1 | 5 in decimal |

