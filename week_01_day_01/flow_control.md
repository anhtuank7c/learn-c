# Flow Control



## 1. If and If else

In software development, there are many scenarios where you need to execute specific blocks of code based on a condition.

For instance:

* Validating Input: If a user enters invalid input, you can display an error message
* Conditional Execution: Perform certain actions only if specific conditions are met

**Syntax**

```c
if (condition) {
  // statements to execute when the condition is true
} else { // optional
  // statements to execute when condition is false
}
```

Example

```c
int x = 10;
if (x > 10) {
  printf("X is greater than 10");
} else {
  printf("X is less than or equal to 10");
}

#include <stdbool.h>

bool is_weather_good = true;
if (is_weather_good) {
  printf("Go out side\n");
}
printf("Have dinner\n");
```

**Important points**

* If there is only **one line of code** in the `if` or `else` block, the curly braces `{}` are optional

  ```c
  if (3 > 5) printf("3 > 5"); else printf("3 <= 5"); // online of code
  
  if (3 > 5) printf("3 > 5"); // one line of code
  ```

* However, if you have more than one statement to execute, curly braces are required

  ```c
  if (3 > 5)
    printf("A");
    printf("B");
    printf("C");
    printf("D");
    printf("E");
  // A only printed if 3 > 5
  // BCDE always be printed
  
  // rewrite example from above, same logic, same result
  if (3 > 5)
    printf("A");
  printf("B");
  printf("C");
  printf("D");
  printf("E");
  
  if (3 > 5) {
    printf("A");
    printf("B");
    printf("C");
    printf("D");
    printf("E");
  }
  // ABCDE will be printed only if 3 > 5
  ```

* Proper indentation is important for readability, even though the compiler doesn't enforce it

  ```c
  	if (5 > 3) {
  printf("A");
  printf("B");
  printf("C");
  printf("D");
  printf("E");
  	}
  // still print ABCDE, no error throwed
  ```

* Code formating & stype should follow your's organization style standard