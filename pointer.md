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

