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

### 3.2 printf

`printf` is used for writing data to the standard output device. It can be used for displaying integers, float, characters and strings.

### 3.3 fgets

`fgets` reads strings, including those with spaces, from the standard input or file streams. Originally designed for file input but can also be used for standard input

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

