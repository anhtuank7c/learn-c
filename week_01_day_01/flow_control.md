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

## 2. Else if

The **else if statement** is conditional statement used for multiple conditional checks. It contains additional blocks of code for each condition specified in the else if.

**Syntax**

```c
if (condition) {
  // do something
} else if (another_condition) {
  // do something
} else {
  // do something
}
```

Example

```c
int x;
printf("Enter an integer: ");
scanf("%d", &x);
if (x < 10) {
    printf("%d < 10\n", x);
} else if (x < 50) {
    printf("%d < 50\n", x);
} else if (x < 80) {
    printf("%d < 80\n", x);
} else {
    printf("%d >= 80\n", x);
}
```

## 3. Nested if-esle

Nested if-else statements are used when we have a set of conditions to be tested, and each condition has further conditions to be tested. The nested if-else structure allows us to group multiple conditions in a hierarchical way.

Example

```c
int main(void) {
    int x;
    printf("Enter an integer (0-10): ");
    scanf("%d", &x);
    if (x < 0 || x > 10) {
        printf("Invalid input\n");
        return 1;
    }
    if (x < 6) {
      	// nested
        if (x < 5) {
            printf("Too weak\n");
        } else {
            printf("Normal strength\n");
        }
    } else if (x < 8) {
        printf("Moderate strength\n");
    } else {
        printf("Strong\n");
    }
    return 0;
}
```

## 4. Switch Statement

The ***\*switch\**** statement in C is a control structure that allows for the execution of a block of code from multiple blocks based on the value of a single variable called control variable. It is an alternative for long if statements.

**Syntax**

```c
switch (control_variable) {
  case value_1:
    // do something
    break;
  // union cases
  case value_2:
  case value_3:
    // do something
    break;
  default:
    // do something
}
```

Example

```c
int x;
printf("Enter an integer (0-10): ");
scanf("%d", &x);
switch (x) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        printf("Too weak\n");
        break;

    case 6:
    case 7:
        printf("Moderate\n");
        break;

    case 8:
        printf("Strong\n");
        break;

    case 9:
    case 10:
        printf("Super strong\n");
        break;
    default:
        printf("Wrong input\n");
}
```

