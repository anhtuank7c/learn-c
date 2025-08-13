# Accelerated C Programming for Experienced Programmers (2 Weeks)

I had been learned C in university but honestly, that was useless and I am not good at programming at that time, I also have no idea what a real-life C program is, the university also don't require students to make a real application.  They just want us to do Math in C. It doesn't make any sense.

After roughly 14 years of working in Software industry, I approved myself to learn C again, my purpose is to understand how [PrimJS](https://github.com/lynx-family/primjs) works, how does it share the native object between JS and native world.

I have many years working with React Native but [Lynx](https://lynxjs.org/) is a new wind in hybrid framework, I need to understand it.

**Caution: This course is made for experienced programmers**

### Disclaimer

> I am not writing the whole content all by myself, I learn from many sources and rewrite by my understanding. If any one found copyright issues, please contact me with evidence, I am happy to cooperate with you to take it down or highlight your credits for that. Plus, I share the whole content for free, not for commercial purpose.

**Reference Sources:**

- AI (Grok, ChatGPT)
- geeksforgeeks.org
- c-language.org
- cprogramming.com

## Week 1: C Fundamentals and Professional Development Practices

### [Day 1: C Language Essentials and Development Environment](./week_01_day_01/README.md)

- C language overview and distinguishing features
- Setting up a professional development environment
- Compilation process and build tools
- Basic syntax, functions, and program structure
- Memory model and execution flow
- **Debugging**: Using debuggers (GDB, LLDB) and debug builds
- **Practice**: Create a multi-file program with debugging configuration

### Day 2: Data Types, Memory Management, and Pointers

- Primitive types, modifiers, and type conversions
- Variables, scope, and storage classes
- Pointers fundamentals and pointer arithmetic
- Dynamic memory allocation and management
- Memory leak detection tools (Valgrind, AddressSanitizer)
- **Testing**: Unit testing memory management functions
- **Practice**: Implement a dynamic array with memory tests

### Day 3: Arrays, Strings, and Memory Operations

- Array implementation and relationship to pointers
- String handling in C (null-terminated strings)
- Memory manipulation functions (memcpy, memmove, memset)
- Cache-friendly data structures and algorithms
- **Debugging**: Finding buffer overflows and memory corruption
- **Practice**: Build a string library with comprehensive tests

### Day 4: Structures, Complex Data Types, and Testing

- Struct and union definitions and memory layout
- Self-referential structures and complex data structures
- Function pointers and callbacks
- **Testing Framework**: Introduction to frameworks (Unity, Check, CUnit)
- Test-driven development (TDD) in C
- **Practice**: Implement a hash table with complete test suite

### Day 5: Database Programming in C

- Introduction to database APIs in C (SQLite, libpq, MySQL C API)
- Connection management and connection pooling
- Executing queries and handling result sets
- Prepared statements and parameterized queries
- Transaction management
- Error handling in database operations
- **Practice**: Build a database access layer with connection pooling

## Week 2: Advanced Topics and Building a Real Application

### Day 6: Concurrency, Parallel Programming, and Thread-safe Database Access

- Process vs. threads programming
- POSIX threads (pthreads) API
- Mutex, semaphores, and condition variables
- Thread safety and race conditions
- Thread-safe database operations
- Connection pooling in multi-threaded environments
- **Practice**: Implement a thread-safe database service

### Day 7: Performance Optimization and Profiling

- Compiler optimization flags
- Profiling tools (gprof, perf, Valgrind)
- Database query optimization
- Statement caching and batch operations
- CPU cache considerations and alignment
- **Testing**: Performance benchmarking methodologies
- **Practice**: Optimize database operations and benchmark results

### Day 8: System Programming and I/O Models

- File I/O and buffering strategies
- Socket programming and network I/O models
- Non-blocking I/O techniques
- Memory-mapped files for performance
- I/O multiplexing for database and network operations
- **Debugging**: Network and I/O debugging tools
- **Practice**: Build a non-blocking server with database integration

### Day 9: Integration Testing and Continuous Integration

- Integration testing with databases
- Test fixtures and database setup/teardown
- Mocking database connections for unit tests
- Database migration for testing
- Continuous integration for C projects
- Code coverage tools (gcov, lcov)
- **Practice**: Create a test suite with database integration tests

### Day 10: Final Project - Server Monitoring Application with Database

- Architecture design with database persistence
- Concurrent implementation with thread-safe database access
- Database schema design for metrics storage
- Query optimization for metrics retrieval
- Performance benchmarking of database operations
- **Final Project**: Complete server monitoring application with database backend

## Final Project Overview

By the end of this course, you'll have built a server monitoring application that:

1. Collects system metrics (CPU, memory, disk, network) efficiently
2. Stores collected metrics in a database (SQLite or similar)
3. Uses a thread pool for concurrent processing
4. Implements thread-safe database operations
5. Features optimized queries for metrics storage and retrieval
6. Includes a complete test suite with database integration tests
7. Demonstrates professional-grade C programming practices
8. Supports configuration via files
9. Implements robust error handling and recovery
