# Loop

A loop is a way to **execute a block of code multiple times** without writing it repeatedly.

**Example without loop**

```c
printf("Hello world\n");
printf("Hello world\n");
printf("Hello world\n");
printf("Hello world\n");
printf("Hello world\n");
```

**Example with loop**

```c
for (int i = 0; i < 5; i++) {
  printf("Hello world\n");
}
```

## 1. While

Best when you **don’t know how many times**, but you have a condition to check before each iteration.

Loop body will be infinite execute unless condition is false. Be aware of this.

**Syntax**

```c
while (condition_still_true) {
  // loop body
}
```

**Example**

```c
int count = 0;
while (count < 3) {
  printf("%d: Hello world\n", count);
  count++;
}

/* Result
0: Hello world
1: Hello world
2: Hello world
*/
```

## 2. For

Best when you **know how many times** you want to repeat.

**Syntax**

```c
for (initialization; condition; update) {
  // loop body
}
```

**Example**

```c
for (int i = 0; i < 5; i++) {
  printf("%d: Hello world\n", count);
}
```

## 3. Do while

Similar to `while`, but **executes at least once** (condition checked *after* the loop body).

Loop body will be infinite execute unless condition is false. Be aware of this.

**Syntax**

```c
do {
  // loop body
} while (condition);
```

**Example**

```c
int count = 0;
do {
  printf("%d: Hello world\n", count);
  count++;
} while (count > 5);
```

## 4. Special Control Keywords

### 4.1 break

 ***break*** statement is used to exit loops or switch statement prematurely before their complete execution. It provides a way to terminate the execution of a loop even when the loop condition remains true.

```c
// example 1
int count = 0;
while (count < 5) {
  if (count == 3) {
    break; // exit loop
  }
  // loop body
  count++;
}

// example 2
for (int i = 0; i < 5; i++) {
  if (i == 3) {
    break; // exit loop
  }
  // loop body
}

// example 3
int count = 0;
do {
  if (count == 3) {
    break; // exit loop
  }
  // loop body
  count ++;
} while (count < 5);

switch (count) {
  case 3:
    printf("Found number 3");
    break;
  default:
    printf("Not found number 3");
}
```

### 4.2 continue

The ***continue*** keyword is used inside loops to skip to the next iteration without executing the code present after itself.

```c
for (int i = 0; i < 5; i++) {
    if (i == 2) continue;
    printf("%d ", i);
}
// Output: 0 1 3 4
// Skipped: 2
```

### 4.3 goto

`goto` in C is a **jump statement** — it transfers control directly to a labeled statement within the same function. It’s considered a bit "dangerous" if abused, but it still has some **valid real-world uses** (like breaking out of deeply nested loops or error handling).

**Example 1**

```c
#include <stdio.h>

int main() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 2) {
                goto end_loops;  // exit both loops at once
            }
            printf("i=%d, j=%d\n", i, j);
        }
    }

end_loops:
    printf("Exited loops.\n");
}
```

**Example 2**: handling error with `goto` label

```c
#include <stdio.h>

int main() {
    FILE *file = fopen("data.txt", "r");
    if (!file) {
        goto error;
    }

    // simulate reading file...
    printf("File opened successfully!\n");

    fclose(file);
    return 0;

error:
    printf("Error: Could not open file!\n");
    return 1;
}
```

