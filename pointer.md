# Pointer

## 1. Application of pointer

### 1.1 **Changing passed parameter**

​	By default, parameters passed to function are passed by value. Whatever change is done to them inside the function does 	not affect the actual variable.

​	Pointers are used when the need is to modify the variables inside a function. Languages like C++ and Java support references 	for such purpose, but C only uses pointers.

### 1.2 **Passing large object efficiently**

In C, passing large objects to functions by value leads to the creation of a copy the entire object into the function's local variables, which is very inefficient. Pointers solve this problem by passing the address of the objects, allowing the function to access it directly without copying.

### 1.3 **Dynamic memory allocation**

Dynamic memory allocation and dellocation in C allow programmers to allocate memory during runtime and release it when no longer needed. Pointers store the address of dynamically allocated memory.

### 1.4 **Implement data structure like Linked List, Tree, Binary Search, etc...**

Data structures like Linked List, trees, and graphs often require nodes that are not stored continuously in memory. Pointers help link these nodes by storing the address of the next nodes thus allows the creation of dynamic and flexible data structures in C.

### 1.5 **System level programming**

Pointers play a major role in multi-threading and inter-process communication. They take care of the shared memory blocks in case multiple processes access them.

### 1.6 **Returning multiple values from Functions**

C functions typically return a single value. However multiple values can be returned by passing the addresses of the variables to the function and storing it in a pointer.

### 1.7 **Accessing array element**

Internally, C uses pointer arithmetic to access elements of arrays. Understanding the relationship between arrays and pointers allows the users to direct access to array elements from anywhere if they have the address.

### 1.8 **Passing arrays to Functions**

Passing larges arrays values by value in C is inefficient, as it requires copying the entirely array. Instead, arrays are passed as pointers, where only the address of the first element is passed, allowing functions to work with the original array efficiently.

## 2. Address and deference Operator in C

To understand pointer in C programming language, we first need to know about two operators and that are extensively used while working with pointers.

They are:

* Addressof operator `&`
* Dereference operator `*`

### 2.1 Addressof operator `&`

Address of operator is denoted by `&` ampersand symbol and gives you the memory address of a given variable when place before a variable name as shown:

`&variable_name`

### 2.2 Deference operator `*`

The deference operator is denoted by `*` asterisk symbol and gives you the value stored at a given memory address stores inside a pointer. It is also placed before the pointer name as shown:

`*pointer_name`

The asterisk `*` serves multiple purpose in C:

* As a deference operator (unary operator)
* As a multiplication operator (binary operator)
* In pointer declaration (syntax, not an operator)

**Example**

```c
#include <stdio.h>
int main() {
    int x = 10;
    printf("Address of x: %p\n", &x);
    printf("Value of address of x: %d", *&x);
    return 0;
}

// Address of x: 0061FF1C
// Value of address of x: 10
```

## 3. Introduction of Pointer

In C programming, pointers are special types of variables that store memory addresses of other variables.

For example, a pointer to integer stores the address of an integer, and pointer to character stores the address of a character variable

**Syntax** `data_type * pointer_name;`

**Example**

`short *age, *day;`

### 3.1 **Initialization**

We then store the address of variable of same data type using address of operator

`pointer_name = &variable_name;`

This can also be done at declaration

### 3.2 Deference

Finally we can access the value stored in the memory address using `*` deference operator

`*pointer_name`

**Example**

```c
#include <stdio.h>
int main() {
    int x = 10;
    int *p = &x;
    printf("Address of x: %p\n", &x);
    printf("Value of address of x: %d\n", *&x);

    printf("Address of x: %p\n", p);
    printf("Value of address of x: %d\n", *p);
    printf("Value of address of p: %p\n", &p);
    return 0;
}
/*
Address of x: 0061FF1C
Value of address of x: 10
Address of x: 0061FF1C
Value of address of x: 10
Value of address of p: 0061FF18
*/

```

### 3.3 Modify values using  pointer

Pointer allow us to modify the values of other variables whose address they store indirectly using deference operator

```c
#include <stdio.h>
int main() {
    int x = 10;
    int *p;
    p = &x;
    printf("Address of x: %p\n", &x);
    printf("Value of address of x: %d\n", *&x);

    printf("Address of x: %p\n", p);
    printf("Value of address of x: %d\n", *p);
    printf("Value of address of p: %p\n", &p);

    // reassign new value to x
    // pointer will also recognize this change
    x = 20;
    printf("Value of address of x: %d\n", x);
    printf("Value of address of x: %d\n", *p);

    // change value of x via pointer p because it store address of x
    *p = *p + 50;
    printf("Value of address of x: %d\n", x);
    printf("Value of address of x: %d\n", *p);
    return 0;
}

/*
Address of x: 0061FF1C
Value of address of x: 10
Address of x: 0061FF1C
Value of address of x: 10
Value of address of p: 0061FF18

Value of address of x: 20
Value of address of x: 20

Value of address of x: 70
Value of address of x: 70
*/
```

### 3.4 Size of pointer

All pointer variables have the same size regardless of their type whether it is integer, character, double or any other type of pointer.

This size depend on the system architecture. If the system is 64 bits, then pointer can be 64-bit long. If the system is 32 bits, then pointer can be 32-bit long.

```c
#include <stdio.h>

int main()
{
    int *p1;
    char *p2;
    double *p3;
    printf("%zu\n", sizeof(p1));
    printf("%zu\n", sizeof(p2));
    printf("%zu\n", sizeof(p3));
    return 0;
}

/*
4
4
4
*/
```

