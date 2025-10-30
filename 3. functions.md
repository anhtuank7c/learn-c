# Functions

Functions helps simplify the code, promote reusability and make program more organized.

There are two way to to define and use function:

* Define the Function Before using it **(1)**
* Declare the Function, Use It, and Then Define It **(2)**

## 1. Define the Function Before using it

This way is order matter, you have to define function before using.

**Syntax**

```c
[return type] [function_name] ([parameters]) {
  // function body
}
```

**Example 1**

```c
/**
 * Greeting function
 * @param name
 * @returns nothing
 */
void greeting(char *name) {
  printf("Hello %s", name);
}

// invoke function
greeting("Tuan");
greeting("Tue Nhi");
```

**Example 2**

```c
/**
 * Sum a and b
 * @param a int
 * @param b int
 * @return sum of a and b
 */
int sum(int a, int b) {
    return a + b;
}

// invoke function
int total = sum(3, 4);
printf("%d\n", total); // 7
```

## 2.  Declare the Function, Use It, and Then Define It

This way is flexible, you just need to declare function before use, the order of define isn't matter. This will gain more benefit when writing C library.

**Example**

```c
void function_name(); // declare function

int main(void) {
  function_name(); // invoke function

  return 0;
}

// define function details
void function_name() {
  // function body
}
```

## 3. Inline function

Inline function is a request (**hint** to the compiler) to insert the function's code directly at the point of call, instead of performing a normal function call (which involves pushing arguments on the stack, jumping to the function, returning back etc...)

So, it's like telling the compiler:

> Instead of jumping to the function, just paste its body here to reduce **function call overhead**

***Normal function call***

```
main()
   |
   +--> call function_name()
             |
             +--> new stack frame
             +--> return value
   <-- return
```



1. Push arguments onto the stack (or into registers, depending on calling convention).
2. Save the return address (so the CPU knows where to come back).
3. Jump (`call`) to the function body.
4. Inside the function, maybe push a new **stack frame** (local variables, saved registers).
5. Execute the body.
6. Pop the stack frame.
7. Return (`ret`) to caller.

That’s the whole **function call overhead**.

With an **inline function** (if the compiler actually inlines it):

```
main()
   |
   +--> directly executes x + y
   (no extra call, no new frame)
```



- The compiler just **copies the function body** into the caller.
- No `call` / `ret`, no extra **stack frame**.
- It’s as if you had written the code directly in `main`.

**Syntax**

```c
// define inline function in header file (.h)

inline function_name(parameters) {
  // function body
}

// if you want inline function in .c file, add prefix "static" keyword
static inline function_name(parameters) {
  // function body
}
```

**Example**

```c
#include <stdio.h>

static inline int sum(int a, int b) {
  return a + b;
}

int main() {
	int x = 5, y = 10;
  printf("x + y = %d", sum(x, y)); //  compiler may replace sum(x, y) by (x + y) directly
  return 0;
}
```

