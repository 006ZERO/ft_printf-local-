*This activity has been created as part of the 42 curriculum by gabusalm.*

# ft_printf

## Description

ft_printf is a custom implementation of the standard C library function `printf()`. The goal of this project is to recreate the behavior of the original `printf()` function, handling various format specifiers and returning the total number of characters printed.

This project is part of the 42 school curriculum and serves as an introduction to variadic functions in C, providing a deeper understanding of formatted memory streams and low-level output manipulation.

### Supported Conversions

| Specifier | Description |
| :---: | :--- |
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%p` | Prints a pointer address in hexadecimal |
| `%d` | Prints a decimal (base 10) number |
| `%i` | Prints an integer in base 10 |
| `%u` | Prints an unsigned decimal number |
| `%x` | Prints a number in hexadecimal (lowercase) |
| `%X` | Prints a number in hexadecimal (uppercase) |
| `%%` | Prints a percent sign |

---

## Instructions

### Compilation

To compile the library, run:

```bash
make
```

This will safely generate `libftprintf.a` at the root of the repository without causing relinking issues.

### Makefile Rules

| Rule | Description |
| :---: | :--- |
| `make` or `make all` | Compiles the library source files |
| `make clean` | Removes object files (`.o`) |
| `make fclean` | Removes object files and the generated library |
| `make re` | Recompiles everything from scratch |

### Usage

1. Include the header in your C file:

```c
#include "ft_printf.h"
```

2. Compile your program alongside the static archive:

```bash
cc -Wall -Wextra -Werror your_program.c -L. -lftprintf -o your_program
```

### Example

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "World");
    ft_printf("Number: %d\n", 42);
    ft_printf("Hex: %x\n", 255);
    ft_printf("Pointer: %p\n", &main);
    return (0);
}
```

---

## Algorithm and Data Structure

### Chosen Data Structure & Justification
The foundational data structure driving this project is the **Variadic Argument List (`va_list`)** provided by `<stdarg.h>`. 

* **Justification:** Because `printf` must accept an unpredictable number of parameters with changing data types, static data structures (like arrays or standard structs) are completely unviable. The `va_list` structure acts as a sequential pointer stream that walks down the stack framework, retrieving parameters based dynamically on the data type requested by the parsing loop.

### Algorithm Design & Justification
The implementation applies a **Linear Token-Parsing Engine with Stack-Bubbled Counter Accumulation**:
1. It loops through the format string character by character. Standard bytes are pushed directly to `write()`.
2. Upon hitting `%`, it shifts tracking to an evaluation router to identify the target conversion type.
3. Every individual utility function actively increments and returns an integer character count rather than tracking globally.

* **Justification for Modular Helpers over Mono-Buffer:** Writing dedicated conversion helper functions (`ft_puthex`, `ft_putptr`, etc.) maximizes modular isolation. Each can be independently unit-tested for boundary overflow errors (like `INT_MIN`) without risking structural instability inside the primary string processing engine.
* **Justification for Counter Bubbling (`count += ...`):** Passing and returning local tracking counts across the recursive call-stack ensures thread-safe, consistent accounting without relying on unsafe global state parameters.
* **Justification for Recursion over Iteration:** Modulo-driven recursion (`nb / 16`, `nb / 10`) naturally leverages the call-stack to reverse numeric outputs from left-to-right. This eliminates the memory management overhead and allocation leaks that occur when creating intermediate dynamic array buffers (`malloc`).

---

## Resources

### Documentation

* [printf(3) - Linux manual page](https://man7.org)
* [Variadic Functions in C](https://cppreference.com)
* [stdarg.h documentation](https://opengroup.org)
* [42 Docs - ft_printf](https://github.io)

### AI Usage Disclosure
In accordance with 42 campus guidelines, an AI assistant was utilized to review code logic and ensure compliance across specific edge-case scenarios:
* **Tasks Assigned:** Code structural review, boundary checking for numerical overflow, and debugging memory parsing behaviors.
* **Parts Impacted:** 
  - Refactoring signed integer conversions to use an isolated `long` configuration to stop `INT_MIN` overflows.
  - Rectifying pointer indexing loops inside `ft_printf` to handle trailing `%` characters without scrolling into unallocated heap space.
  - Adding defensive structural tracking to ensure `va_end` is invoked across early-exit error paths to avoid memory allocation leakage.
* All code logic and final implementation decisions were verified, tested, and finalized by the student to guarantee true comprehension during peer evaluations.
