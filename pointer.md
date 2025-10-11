# Pointer

## Application of pointer

* Changing passed parameter
* Passing large object efficiently
* Dynamic memory allocation
* Implement data structure like Linked List, Tree, Binary Search, etc...
* To do system level programming
* To return multiple value
* Used for accessing array element
* To pass array parameters

## Address and deference Operator in C

To understand pointer in C programming language, we first need to know about two operators and that are extensively used while working with pointers.

They are:

* Addressof operator `&`
* Dereference operator `*`

### Addressof operator `&`

Address of operator is denoted by `&` ampersand symbol and gives you the memory address of a given variable when place before a variable name as shown:

`&variable_name`

### Deference operator `*`

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

## Introduction of Pointer

In C programming, pointers are special types of variables that store memory addresses of other variables.

For example, a pointer to integer stores the address of an integer, and pointer to character stores the address of a character variable

### **Syntax**

`data_type * pointer_name;`

**Example**

`short *age, *day;`

### **Initialization**

We then store the address of variable of same data type using address of operator

`pointer_name = &variable_name;`

This can also be done at declaration

### Deference

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

### Modify values using  pointer

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

### Size of pointer

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

