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



