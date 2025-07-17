# C Programming Learning Guide

## Table of Contents
1. [Introduction to C](#introduction-to-c)
2. [Setting Up Your Environment](#setting-up-your-environment)
3. [Basic Syntax and Structure](#basic-syntax-and-structure)
4. [Data Types and Variables](#data-types-and-variables)
5. [Input/Output Operations](#inputoutput-operations)
6. [Control Structures](#control-structures)
7. [Functions](#functions)
8. [Arrays and Strings](#arrays-and-strings)
9. [Pointers](#pointers)
10. [Memory Management](#memory-management)
11. [Structures and Unions](#structures-and-unions)
12. [File I/O](#file-io)
13. [Practice Exercises](#practice-exercises)

## Introduction to C

C is a powerful, general-purpose programming language developed by Dennis Ritchie at Bell Labs in 1972. It's known for:
- **Low-level access**: Direct memory manipulation
- **Efficiency**: Fast execution and minimal overhead
- **Portability**: Code can run on different platforms
- **Foundation**: Many modern languages are based on C

## Setting Up Your Environment

To compile and run C programs, you'll need a C compiler. On Linux, GCC (GNU Compiler Collection) is commonly used.

### Installing GCC (if not already installed)
```bash
sudo apt update
sudo apt install gcc
```

### Basic compilation command
```bash
gcc filename.c -o outputname
./outputname
```

## Basic Syntax and Structure

Every C program has a basic structure:

```c
#include <stdio.h>  // Preprocessor directive

int main() {        // Main function - entry point
    // Your code here
    return 0;       // Return statement
}
```

### Key Points:
- `#include` directives include header files
- `main()` function is where execution begins
- Statements end with semicolons (`;`)
- Code blocks are enclosed in curly braces `{}`
- Comments: `//` for single line, `/* */` for multi-line

## Data Types and Variables

### Primitive Data Types

| Type | Size | Range | Format Specifier |
|------|------|-------|------------------|
| `char` | 1 byte | -128 to 127 | `%c` |
| `int` | 4 bytes | -2,147,483,648 to 2,147,483,647 | `%d` |
| `float` | 4 bytes | ~6 decimal places | `%f` |
| `double` | 8 bytes | ~15 decimal places | `%lf` |

### Variable Declaration and Initialization
```c
int age = 25;           // Declaration with initialization
float pi = 3.14159;     // Float variable
char grade = 'A';       // Character variable
double salary;          // Declaration without initialization
salary = 50000.50;      // Assignment
```

### Constants
```c
const int MAX_SIZE = 100;    // Constant variable
#define PI 3.14159           // Macro constant
```

## Input/Output Operations

### Output with printf()
```c
#include <stdio.h>

int main() {
    int num = 42;
    float pi = 3.14159;
    char letter = 'C';
    
    printf("Integer: %d\n", num);
    printf("Float: %.2f\n", pi);     // .2f for 2 decimal places
    printf("Character: %c\n", letter);
    printf("String: %s\n", "Hello World");
    
    return 0;
}
```

### Input with scanf()
```c
#include <stdio.h>

int main() {
    int age;
    float height;
    char name[50];
    
    printf("Enter your age: ");
    scanf("%d", &age);              // Note the & (address operator)
    
    printf("Enter your height: ");
    scanf("%f", &height);
    
    printf("Enter your name: ");
    scanf("%s", name);              // No & for arrays
    
    printf("Hello %s, you are %d years old and %.1f feet tall.\n", 
           name, age, height);
    
    return 0;
}
```

## Control Structures

### Conditional Statements

#### if-else
```c
#include <stdio.h>

int main() {
    int score;
    printf("Enter your score: ");
    scanf("%d", &score);
    
    if (score >= 90) {
        printf("Grade: A\n");
    } else if (score >= 80) {
        printf("Grade: B\n");
    } else if (score >= 70) {
        printf("Grade: C\n");
    } else if (score >= 60) {
        printf("Grade: D\n");
    } else {
        printf("Grade: F\n");
    }
    
    return 0;
}
```

#### switch-case
```c
#include <stdio.h>

int main() {
    char operator;
    float num1, num2, result;
    
    printf("Enter operator (+, -, *, /): ");
    scanf("%c", &operator);
    
    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);
    
    switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                printf("Error: Division by zero!\n");
                return 1;
            }
            break;
        default:
            printf("Invalid operator!\n");
            return 1;
    }
    
    printf("%.2f %c %.2f = %.2f\n", num1, operator, num2, result);
    return 0;
}
```

### Loops

#### for loop
```c
#include <stdio.h>

int main() {
    // Print numbers 1 to 10
    for (int i = 1; i <= 10; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    // Multiplication table
    int num = 5;
    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", num, i, num * i);
    }
    
    return 0;
}
```

#### while loop
```c
#include <stdio.h>

int main() {
    int num, sum = 0;
    
    printf("Enter numbers to sum (0 to stop): \n");
    while (1) {  // Infinite loop
        scanf("%d", &num);
        if (num == 0) {
            break;  // Exit the loop
        }
        sum += num;
    }
    
    printf("Sum: %d\n", sum);
    return 0;
}
```

#### do-while loop
```c
#include <stdio.h>

int main() {
    int choice;
    
    do {
        printf("\n--- Menu ---\n");
        printf("1. Option A\n");
        printf("2. Option B\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("You selected Option A\n");
                break;
            case 2:
                printf("You selected Option B\n");
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);
    
    return 0;
}
```

## Functions

Functions help organize code into reusable blocks.

### Function Declaration and Definition
```c
#include <stdio.h>

// Function declaration (prototype)
int add(int a, int b);
float calculateArea(float radius);
void printMessage(void);

int main() {
    int sum = add(5, 3);
    printf("Sum: %d\n", sum);
    
    float area = calculateArea(2.5);
    printf("Area: %.2f\n", area);
    
    printMessage();
    
    return 0;
}

// Function definitions
int add(int a, int b) {
    return a + b;
}

float calculateArea(float radius) {
    return 3.14159 * radius * radius;
}

void printMessage(void) {
    printf("Hello from a function!\n");
}
```

### Function with Arrays
```c
#include <stdio.h>

void printArray(int arr[], int size);
int findMax(int arr[], int size);

int main() {
    int numbers[] = {3, 7, 1, 9, 4, 6, 2};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    printArray(numbers, size);
    int max = findMax(numbers, size);
    printf("Maximum value: %d\n", max);
    
    return 0;
}

void printArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
```

## Arrays and Strings

### Arrays
```c
#include <stdio.h>

int main() {
    // Array declaration and initialization
    int numbers[5] = {1, 2, 3, 4, 5};
    int scores[] = {85, 92, 78, 96, 88};  // Size determined by elements
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    
    // Accessing array elements
    printf("First number: %d\n", numbers[0]);
    printf("Last number: %d\n", numbers[4]);
    
    // Modifying array elements
    numbers[2] = 10;
    
    // Iterating through array
    for (int i = 0; i < 5; i++) {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }
    
    // 2D array
    printf("\nMatrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
```

### Strings
```c
#include <stdio.h>
#include <string.h>

int main() {
    // String declaration and initialization
    char name1[20] = "John";
    char name2[] = "Alice";
    char name3[20];
    
    // String input
    printf("Enter your name: ");
    fgets(name3, sizeof(name3), stdin);
    
    // Remove newline from fgets
    name3[strcspn(name3, "\n")] = 0;
    
    // String functions
    printf("Length of name1: %lu\n", strlen(name1));
    printf("Comparing name1 and name2: %d\n", strcmp(name1, name2));
    
    // String concatenation
    char fullName[50];
    strcpy(fullName, name1);
    strcat(fullName, " ");
    strcat(fullName, name2);
    printf("Full name: %s\n", fullName);
    
    return 0;
}
```

## Pointers

Pointers store memory addresses of variables.

### Basic Pointers
```c
#include <stdio.h>

int main() {
    int num = 42;
    int *ptr = &num;  // ptr stores the address of num
    
    printf("Value of num: %d\n", num);
    printf("Address of num: %p\n", (void*)&num);
    printf("Value of ptr: %p\n", (void*)ptr);
    printf("Value pointed by ptr: %d\n", *ptr);
    
    // Modifying value through pointer
    *ptr = 100;
    printf("New value of num: %d\n", num);
    
    return 0;
}
```

### Pointers and Arrays
```c
#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr;  // arr is equivalent to &arr[0]
    
    // Accessing array elements using pointers
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d, *(ptr + %d) = %d\n", 
               i, arr[i], i, *(ptr + i));
    }
    
    // Pointer arithmetic
    printf("\nUsing pointer arithmetic:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *ptr);
        ptr++;  // Move to next element
    }
    printf("\n");
    
    return 0;
}
```

### Function Pointers
```c
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int main() {
    // Function pointer declaration
    int (*operation)(int, int);
    
    // Assign function to pointer
    operation = add;
    printf("5 + 3 = %d\n", operation(5, 3));
    
    operation = multiply;
    printf("5 * 3 = %d\n", operation(5, 3));
    
    return 0;
}
```

## Memory Management

### Dynamic Memory Allocation
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter number of integers: ");
    scanf("%d", &n);
    
    // Allocate memory for n integers
    int *arr = (int*)malloc(n * sizeof(int));
    
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Input values
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Display values
    printf("You entered: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Free allocated memory
    free(arr);
    arr = NULL;  // Good practice
    
    return 0;
}
```

## Structures and Unions

### Structures
```c
#include <stdio.h>
#include <string.h>

// Structure definition
struct Student {
    int id;
    char name[50];
    float gpa;
};

// Function to display student info
void displayStudent(struct Student s) {
    printf("ID: %d, Name: %s, GPA: %.2f\n", s.id, s.name, s.gpa);
}

int main() {
    // Structure variable declaration and initialization
    struct Student student1 = {101, "Alice", 3.85};
    struct Student student2;
    
    // Assigning values
    student2.id = 102;
    strcpy(student2.name, "Bob");
    student2.gpa = 3.92;
    
    // Displaying student information
    displayStudent(student1);
    displayStudent(student2);
    
    // Array of structures
    struct Student class[3] = {
        {103, "Charlie", 3.67},
        {104, "Diana", 3.78},
        {105, "Eve", 3.91}
    };
    
    printf("\nClass List:\n");
    for (int i = 0; i < 3; i++) {
        displayStudent(class[i]);
    }
    
    return 0;
}
```

## File I/O

### Basic File Operations
```c
#include <stdio.h>

int main() {
    FILE *file;
    char text[100];
    
    // Writing to a file
    file = fopen("sample.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return 1;
    }
    
    fprintf(file, "Hello, World!\n");
    fprintf(file, "This is a test file.\n");
    fprintf(file, "Line number 3.\n");
    fclose(file);
    
    // Reading from a file
    file = fopen("sample.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }
    
    printf("File contents:\n");
    while (fgets(text, sizeof(text), file) != NULL) {
        printf("%s", text);
    }
    fclose(file);
    
    return 0;
}
```

## Practice Exercises

### Exercise 1: Temperature Converter
Create a program that converts temperatures between Celsius, Fahrenheit, and Kelvin.

### Exercise 2: Simple Calculator
Build a calculator that performs basic arithmetic operations using functions.

### Exercise 3: Student Grade Manager
Create a program that manages student records using structures and arrays.

### Exercise 4: Word Counter
Write a program that counts words, characters, and lines in a text file.

### Exercise 5: Bubble Sort
Implement the bubble sort algorithm to sort an array of integers.

### Exercise 6: Linked List
Create a simple linked list implementation with insert, delete, and display operations.

## Next Steps

1. **Practice regularly**: Write small programs daily
2. **Read other people's code**: Study open-source C projects
3. **Learn debugging**: Use GDB (GNU Debugger)
4. **Explore advanced topics**: 
   - Data structures (linked lists, trees, graphs)
   - Algorithms (sorting, searching)
   - System programming
   - Network programming
5. **Build projects**: Create something you're interested in

## Recommended Resources

- **Books**: "The C Programming Language" by Kernighan & Ritchie
- **Online**: GeeksforGeeks, Stack Overflow, GitHub
- **Practice**: LeetCode, HackerRank, Codewars
- **Documentation**: GNU C Library documentation

Happy coding! Remember, the key to learning C is consistent practice and experimentation.