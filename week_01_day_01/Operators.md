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

