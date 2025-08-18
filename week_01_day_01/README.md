# Day 1: C Language Essentials and Development Environment

## 1. Introduction

C is general-purpose, procedural programming language developed in the early 1970s by [*Dennis Ritchie*](https://en.wikipedia.org/wiki/Dennis_Ritchie) at [**Bell Labs**](https://en.wikipedia.org/wiki/Bell_Labs).

It's known for its efficiency, control and flexibility.

Despite being nearly 50 years old, C remains one of the most influential and widely used programming language in the world.

**Key characteristics of C:**

* Efficiency: Close to the hardware, minimal runtime overhead
* Portability: Can run on almost any platform with appropriate compiler
* Power and flexibility: Low-level memory access with high-level constructs
* Small core language: Relatively few keywords (~32)
* Rich Ecosystem: Extensive standard library and third-party libraries

**Why is C still relevant today?**

* Operating system (Linux, Unix, Windows kernels)
* Embedded systems and IoT devices
* Performance-critical applications
* System-level programming
* Foundation for others languages (C++ Objective-C, Javascript, Java)
* Database engines and network servers

### Pros and cons of C

**Pros**

- Efficicency: C is fast and efficient language that can be used to create high-performance applications, especially on a low/cheap hardware (i.e ESP32)
- Portability: C can be compiled and run on wide range of platforms and operating systems
- Low-level access: C provides low-level access to system resources, making it ideal for systems programming and developing operating systems.
- Widely used: C is widely used language, many modern programming languages are built on top of it (Go, JS, Java, Python etc...)

**Cons**

- Difficult: especially for beginners due it its complex syntax and low-level access to system resources
- Lack of memory management: C does not provide automatic memory management which can lead to memory leaks and other memory related bugs if not handled properly 
- No built-in support for OOP: C is procedural programming language so it is not designed to write OOP applications.
- No built-in support for concurrency: it more difficult to write multithreaded applications compared to languages like Java or Go
- Security vulnerabilities: C programs are prone to security vulnerabilities, such as buffer overflows, if not written carefully. (You need to maintain memory carefully)

Overall C is a powerfull language with many advantages, but also requires a high degree of expertise to use effectively and has some potential drawbacks, especially for beginners or developers working on complex projects.

>  Manage memory manually is hard but not impossible, I can do it so you can also do it. Just need to follow an effective strategy. Everything will be alright, don't worries.

## 2. Setting up a professional Development Environment

> This course is designed for experienced developers so I considered you are familiar with these tools.

**2.1 Compiler options:**

* [GCC (GNU Compiler Collection)](https://gcc.gnu.org/): Standard on Linux/macOS
* [Clang](https://clang.llvm.org/): Modern compiler with excellents error messages
* [MinGW](https://www.mingw-w64.org/)/[MSYS2](https://www.msys2.org/): GCC for Windows

**2.2 Build systems:**

* [Make](https://www.gnu.org/software/make/): Traditional build tool for C
* [CMake](https://cmake.org): Modern, cross-platform build system
* [Ninja](https://ninja-build.org/): Fast, lightweight build system

**2.3 Editors/IDE:**

* [VS Code](https://code.visualstudio.com/): with C/C++ extension (free)
* Xcode: available on MacOS (free)
* [Vim](https://www.vim.org/)/[Emacs](https://www.gnu.org/software/emacs/): with plugins for experienced users (free)
* [Clion IDE](https://www.jetbrains.com/clion/): Nice and efficient IDE for C and C++ (paid and free edition)
* [CodeBlocks](https://www.codeblocks.org/downloads/): Free and lightweight IDE
* And much more, you can searching for it on Google Search

**2.4 Debugging Tools:**

* GDB: Standard GNU debugger
* LLDB: LLVM debugger (often used with Clang)
* Valgrind/Leaks: Memory error detector
* Built-in feature of Clion IDE

**2.5 Version Control:**

* Git: essential for any professional development

## 3. Setup Instructions

**3.1 Linux (Ubuntu/Debian)**

```bash
# Install compiler and essential build tools
sudo apt update
sudo apt install build-essential gdb cmake

# Install version control
sudo apt install git

# Install Valgrind for memory checking
sudo apt install valgrind
```

**3.2 macOS**

```bash
# Install Xcode Command Line Tools (includes clang)
xcode-select --install

# Install Homebrew
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# We use leaks on Mac since it don't require additional package being installed on your Mac
# and Valgrind is not compatible with M-series Chip

# Enable stack logs
export MallocStackLogging=1

# Execute your program, stack logs being generated
./your_program

# check for memory leak, it will notice which line of code are leaking
leaks --atExit --list -- ./your_program

# checkout this video for more details
# https://youtu.be/bhhDRm926qA?si=Z64UnODOtYoBFhwn

```

**3.3 Windows**

```bash
# Install MSYS2 from https://www.msys2.org/
# Then open MSYS2 terminal and run:
pacman -Syu
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-gdb mingw-w64-x86_64-cmake
```

## 4. The compilation process

There are 4 main phases in compilation process. Understand this is crucial for effective C programming

**4.1 Preprocessing**

* Removal of comments
* Expansion of macros
* Expansion of includes header files
* Conditional compilation directives

Command: `gcc -E helloworld.c -o helloworld.i`

**4.2 Compilation**

* Translate preprocessed code to [assembly language](https://en.wikipedia.org/wiki/Assembly_language)
* Command: `gcc -S helloworld.i -o helloworld.s`

**4.3 Assembly**

* Converts assembly code to object code
* Command: `gcc -c helloworld.s -o helloworld.o`

**4.4 Linking**

* Combines object files with libraries
* Create executable or library

Linking can be 2 types:

- Static linking: all the code is copied to the single file and then executable file is created
- Dynamic linking: Only the names of the shared libraries is added to the code and then it is referred during the execution

Command: `gcc helloworld.o -o helloworld`



Take a look at compiled files to have better understanding.

![Compilation processes](./compilation_process_files.png)

Each command from above is just for explanation, you can directly compile C code into executable file like command from below:

```bash
gcc helloworld.c -o helloworld
```

**There are several important compiler flags you might want to use**

* `-Wall -Wextra -Werror`: Enable warnings and treat them as errors
* `-g`: Include debugging information
* `-00` though `-03`: Optimize levels from low to high 
* `--std=c99`or `--std=c11`: Specify C language standard

There are several common C standard you might heard are: [ANSI C, C89, C99, C11, C17, C23](https://en.wikipedia.org/wiki/ANSI_C)

> If you have `gcc version 11+` installed on your computer, default C standard would be C17 + GNU extension. Command to check: `gcc -dM -E - < /dev/null | grep __STDC_VERSION__`

## 5. Basic syntax, functions, and program structure

### **5.1 C Program structure**

```c
// Preprocessor directives
#include <stdio.h>
#define MAX_SIZE 100 // defines a macro. During preprocessing, every occurrence of MAX_SIZE in the code will be replaced with the literal 100 before compilation.

// In modern C, people often prefer this way to define a constant
const int MAX_SIZE = 100;

// global variables and declarations
int global_int_variable;
float global_currency;

// function prototype
void function_name(int param_a);
int calculate_distance(const char *location_a, const char *location_b);

typedef struct User {
  char *fullname;
  short age;
  float salary;
  float expenses;
};

// main function - entry point of C program
int main(int argc, char *argv[]) {

  // local variable declarations
  int age = 30;
  char name[20] = "Tuan";
  
  // statements and expressions
  printf("Hello %s, you are %d year old\n", name, age);
  
  // function calls
  int distance = calculate_distance("Vietnam", "Sweden");
  User me = {
    .fullname = "Tuan Nguyen",
    .age = 36,
    .salary = 10.1234,
    .expenses = 1.23
  };
  
  struct Profile {
      char *name;
      short age;
      bool willing_to_relocate;
      float min_monthly_income;
      char *currency;
  } const me = {
      .name = "Tuan Nguyen Anh",
      .age = 36,
      .willing_to_relocate = true,
      .min_monthly_income = 100.12,
      .currency = "VND"
  };
  
  printf("Distance is %d", distance);
  
  /**
  * return exist status of your program to the operating system
  * 0: success execution
  * non-zero: error or specific exit code
  * example of custom code.
  * 1: generic error
  * 2: misuse of shell commands
  * 127: command not found (linux shells)
  **/
  return 0;
}

// function definition
int calculate_distance(const char *location_a, const char *location_b) {
  printf("Calculating distance between %s and %s\n", location_a, location_b);
  return 10 * MAX_SIZE; // MAX_SIZE is replaced by 100 during preprocessor process.
}
```

**Key components:**

* Preprocessor directives: start with `#` processed before compilation
* Functions: self-contained blocks of code
* `main()` or `main(int argc, char *argv[])`: Special function where execution begin
* Statements: individual instructions ending with semicolons `;`
* Comments: `// single comment`or `/* multi-line comments */` (C99 and later)



**Do you wonder why the `main` function needs to return an `int`?**

In C, the language standard requires `main` to return an integer. This integer becomes the program’s **exit code**, which the operating system records when the program finishes.

This is not unique to C — **every program in any programming language** runs as a process in the operating system, and every process has:

- A **PID** (Process ID) so the OS can track and manage it.
- An **exit code** so the OS and other programs can know how it finished.

If you don’t explicitly set an exit code, your language runtime will set one for you (usually `0` for success). Parent processes (like a shell, script, or service manager) can then use this exit code to trigger specific actions — such as logging, restarting a service, or showing an error message.

I have several documents for exit code:

- https://www.ditig.com/linux-exit-status-codes#list-of-standard-exit-codes
- https://www.agileconnection.com/article/overview-linux-exit-codes
- https://learn.microsoft.com/en-us/windows/win32/debug/system-error-codes--0-499-
- https://developer.apple.com/library/archive/documentation/System/Conceptual/ManPages_iPhoneOS/man3/sysexits.3.html

### **5.2 Basic syntax and Control Structures**

#### 5.2.1 Variables and Data Types

#### Variable definition syntax

Define variables by following pattern: `[data_type] [variable_name] = [initial_value];`

`Initial_value` is optional, you can just define variable like this: `[data_type] [variable_name];`

```c
char letter_a = 'a'; // use single quotes symbol for char (single character literal)
char *name = "Nguyen Anh Tuan"; // use double quotes symbol for string (string literal)
char fullname[5] = "TuanNguyen"; // string is an array of char
printf("%s", fullname); // TuanN // just store 5 characters
short age = 36;
int i = 10; // without modifier
int j; // without modifier and initial value;
j = 20;
```



#### Rules for naming variables

- Must start with a letter or underscore `_`
- Can contain letters, digits, and underscore `_`
- Cannot use C keywords (`int`, `return`, `if` etc...)
- Case-sensitive (`fullName` and `fullname` are different)

You can define multiple variables at once using comma `,` symbol

```c
long first_variable, second_variable;
first_variable = 10;
second_variable = 20;

int first = 1, second = 2, third;
third = 3;
```

or even with an expression

```c
double total_expense = 10200000 - 129320;
printf("\nTotal expense: %f", total_expense); // Total expense: 10070680.000000
```

#### Data types:

##### Basic data types:

- `int`: 4 bytes

- `float`: 4 bytes

- `double`: 8 bytes

- `char`: 1 byte

- `bool`: logically need **1 bit** (physically stored in at least **8 bits** (1 byte) because C standard requires that the size of any object is at least 1 byte = 8 bits).

  ```c
  bool male = true;
  printf("sizes: %d", sizeof(male)); // sizes: 1
  ```

- `void`: 0 byte

C provide several modifications to ***expand*** or ***restrict*** the attributes of fundamental types (adjusting *size*, *range*, *sign* behavior)

- `short`: reduces the size and range of an integer (e.g `short int` typically use 2 bytes). Only valid with `int`. `short = short int`, you can use only keyword `short` to present `short int` but remember it ensure the range will not wider than `int`
- `long`: increases the size and range (e.g., `long int`, `long long int`, `long double`). Usually applied to `int` and `double`. `long = long int` but remember `long` keyword implicitely mean it will ensure range bigger than `int`, you can use only keyword `long` to present `long int`. `long` keyword tell the compiler to make this type wider than plain type (or at least not smaller). It does not guarantee the same size across all platforms. Only valid with `int` or `double`
- `signed`: allows both negative and positive values (default for most integer types). The first bit from the left represent the sign (**1**: for negative, **0**: for positive). i.e `1000 0000 = -128` the first number `1` means `negative`
- `unsigned`: restricts values to non-negative, effectively doubling the positive range. The sign bit from above being use to represent value, no need a bit for the sign.

```c
int age; // 4 bytes
short age; // 2 bytes
short int age; // 2 bytes
unsigned int age; // 2 bytes
unsigned short age; // 2 bytes
long int age; // 8 bytes
long age; // 8 bytes
long long int; // 8 bytes
double age; // 8 bytes
long double age; // 16 bytes
```

**Here's the full chain for standard C data types:**

`sizeof(_Bool) <= sizeof(char) <= sizeof(short) <= sizeof(int) <= sizeof(long) <= sizeof(long long) <= sizeof(float) <= sizeof(double) <= sizeof(long double)`



**Tips**: to storing currency value in your program, I recommend to use type `long long` (8 bytes signed integer). No floating-rounding errors, percise arithmetic, easy comparison.



##### Derived data types:

- `array`
- `pointer`
- `function`



##### User defined data types:

- `union`
- `structure`
- `enum`



**Data types sizes and ranges** (based on architectural and following [IEEE-754 floating point standard](https://en.wikipedia.org/wiki/IEEE_754))

| Type            | Size                                        | Value Range Signed              | Value Range Unsigned |
| --------------- | ------------------------------------------- | ------------------------------- | -------------------- |
| char            | 1 byte (8 bits)                             | -128 to 127                     | 0 to 255             |
| short/short int | 2 bytes (16 bits)                           | -32,768 to 32,767               | 0 to 65,535          |
| int             | 4 bytes (32 bits)                           | -2,147,483,648 to 2,147,483,647 | 0 to 4,294,967,295   |
| long            | 4 bytes (32 bits) / 8 bytes (64 bits)       |                                 |                      |
| long long       | 8 bytes (64 bits)                           |                                 |                      |
| float           | 4 bytes (32 bits)                           |                                 | Not Applicable       |
| double          | 8 bytes (64 bits)                           |                                 | Not Applicable       |
| long double     | typically 16 bytes (x86), 8 or 12 on others |                                 | Not Applicable       |

**Memory allocation of C variables**

When a variable is **declared**, the compiler is told that the variable with the given name and type exists in the program. But no memory is allocated to it yet. Memory is allocated when the variable is **defined**.

The size of memory assigned for variables depends on the type of variable. We can check the size using `sizeof` keyword

```c
int age;
printf("sizeof(age) = %d bytes\n", sizeof(age)); // sizeof(age) = 4 bytes
```

#### 5.2.2 Scope of variable

In C, **scope** defines the part of the program where a variable is accessible. It determines the variable’s lifetime and visibility. There are mainly four types of scope:

1. **Local scope**

   The local scope refers to the region inside a block or a function. It is the space enclosed between the `{}` curly braces symbols.

   - The variables declared within the local scope are called **local variables**
   - Local variables are visible in the block they are declared in and other blocks nested inside that block
   - Local scope is also called **block scope**
   - Local variables have no linkage

   ```c
   #include <stdio.h>
   
   int main(void) {
     {
       int a = 10, b = 20;
       {
         // nested block can access outer variables
         printf("\na = %d, b = %d", a, b);
         {
           // a, b declared again
           // so it cannot access outer variables
           // it access local variables within this scope instead
           float a = 9.9, b = 19.9;
           printf("\na = %f, b = %f", a, b);
         }
         // statement access outer variables
         printf("\na = %d, b = %d", a, b);
       }
     }
     // cannot access any variables since no variables declared
     // within this scope
     printf("\na = %d, b = %d", a, b);
     return 0;
   }
   
   // Result
   // a = 10, b = 20
   // a = 9.900000, b = 19.900000
   // a = 10, b = 20
   ```

2. **Global scope**

   - The variables declared in the global scope are called global variables

   - Global variables are visible in every part of the program

   - Global is also called **File scope** as the scope of an identifier starts at the beginning of the file and ends at the end of the file.

     ```c
     // global scope
     float g = 9.8;
     
     void func_name() {
       printf("G = %f\n", g);
     }
     
     int main(void) {
       printf("G = %f\n", g);
       g = 10;
       func_name();
       return 0;
     }
     
     /*
     Result:
     
     G = 9.800000
     G = 10.000000
     */
     ```

   - Have external linkage by default. It means that the variables declared in the global scope can be accessed in another C source file. Use `extern` keyword for that purpose.

     ```c
     // my_lib.c
     #include <stdio.h>
     
     float pi = 3.141592;
     void print_pi() {
       printf("PI = %f", pi);
     }
     
     // use "static" keyword to restrict access to the my_lib.c file only.
     static float g_force = 9.8;
     
     void print_g_force() {
       printf("G = %f\n", g_force);
     }
     
     // main.c
     #include <stdio.h>
     
     extern float pi;
     extern float g_force;
     
     // define function prototype in my_lib.c
     // you don't have to implement this function since it already defined in my_lib.c
     void print_pi();
     void print_g_force();
     
     int main(void) {
       printf("PI constant: %f", pi);
       print_pi(); // invoke print_pi function from my_lib.c
       print_g_force(); // invoke print_g_force function from my_lib.c
       printf("g_force: %f\n", g_force); // compiler will throw an error at this line
       return 0;
     }
     
     ```

     To restrict access to the current file only, global variables can be marked as `static`



#### 5.2.3 Constant variables

In C, you can create variables whose values cannot be modified after initialization by using the `const` keyword. These are called **constants variables**.

```c
const float PI = 3.1412;

PI = 9.8; // ERROR, cannot reassign value to a constant variable
```

- A `const` variable **must be initialized at the time of declaration** (otherwise it will have an undefined value that cannot be changed later).

- By convention, constants are often written in **UPPER_CASE** to emphasize that they should not be modified, e.g., `PI`, `MAX_SIZE`.

#### 5.3 Comment

Comment being use for explanation purposes. Sometimes you want to explain or take note in your code, that's completely natural and reasonable.

There are 2 kinds of comments:

- **Single line comment**:

  ```c
  // this is a single line comment
  // more line
  // one more
  // TODO: need to investigate
  ```

- **Multiple line comment**

  ```c
  /* this
  is
  multiple lines
  commenting /*
  
  /**
   * or you can
   * write multiple lines
   * like this, elegant and 
   * beautiful
   */
  
  /**
   * @brief Do sum 2 numbers
   * @param a number one
   * @param b number two
   * @return total
   */
  float sum(float a, float b) {
      return a + b;
  }
  ```

  

**Best practices:**

* Write comments that are easy to understand
* Do not comment on every line unnecessarily and avoid writing obvious comments
* Update comments regulary
* Focus on explaining the intent behind the code rather than restating the obvious 

```c
// BAD

// Calculate something
int calc(int a, int b) {}

// Function to calculate total price
// Take base price
// Take tax rate
// Adds them together
// Return the total
long long total_price(long long base_price, double tax_rate) {
	return base_price + (long long)(base_price * (tax_rate / 100.0));
}



// GOOD
/**
 * @brief  Calculate the total price including tax.
 *
 * @param base_price  The base price in cents.
 * @param tax_rate    The tax rate as a percentage (e.g., 5.0 for 5%).
 *
 * @return The total price in cents.
 *
 * @note This function truncates fractional cents.
 */
long long total_price(long long base_price, double tax_rate) {
  // Apply tax and cast to integer cents
  return base_price + (long long)(base_price * (tax_rate / 100.0));
}

// TODO: need concrete implement
void func_name();
```



## 6. Memory model and Execution flow

Understanding C memory model is essential for effective programming.

**6.1 Memory layout**

1. **Text segment** (`.text`): This segment contains the machine code, also known as the program's instructions or executable code. It's where the compiler translates your C code into the binary instructions that the CPU can understand. This segment is read-only to prevent accidental modification of instructions.
2. **Data segment**:
   * Initialized data (`.data`): This segment holds global and static variables that have been explicitly initialized with a value during their declaration.
   * Uninitialized Data (`.bss`): This segment stores global and static variables that have not been explicitly initialized during their declaration. By convention, these variables are automatically initialized to zero by the operating system when the program starts. The name "Block Started by Symbol" is a legacy from older assemblers. (zeroed at startup)
3. **Heap**: Dynamic memory allocation. Grow upwards, managed via functions like `malloc`, `calloc`, `realloc` and `free`
4. **Stack**: Function calls, local variables, function parameters. Grow downwards, managed automatically by the compiler. Each function call creates a new stack frame, once function returns, the stack is being removed.

**Memory layout visualization**

![Memory layout visualization](./memory_layout.jpg)

To have better understanding of memory layout, take a look at code from below:

```c
#include <stdio.h>
#include <stdlib.h>

float global_price_initialized = 199.99; // .data
static int static_global_initialized = 1; // .data

int global_age_not_initialized; // .bss
static double static_global_not_initialized; // .bss

int main() {
  int local_var = 5; // stack
	int *ptr = (int *)malloc(sizeof(int) * 5); // heap
  for (int i = 0; i < 5; i++)
		ptr[i] = i + 1;

  for (int i = 0; i < 5; i++)
    printf("%d \n", ptr[i]);
  free(ptr); // 

  printf("value of .data: %.2f\n", global_price_initialized); // value of .data: 199.99
  printf("value of .bss: %.1f\n", static_global_not_initialized); // value of .bss: 0.0
  return 0;
}
```

**6.2 Execution flow**

1. Program begins at `main()`

2. Function calls push data onto the Stack

3. When a function returns, its stack frame is removed

4. Program continues execution at return point

5. Program terminates when `main()` returns

## 7. Debugging Basics

Debugging is a critical skill for C development.

**7.1 GDB (GNU Debugger)**
