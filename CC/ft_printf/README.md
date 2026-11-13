*This project has been created as part of the 42 curriculum by asidki.*

# ft_printf

## Description

**ft_printf** is a mandatory project within the 42 school curriculum. The goal of this project is to recreate the behavior of the standard C library function `printf(3)`.

Writing `ft_printf` from scratch deepens understanding of low-level software engineering concepts:
- **Variadic Functions in C:** Working with `<stdarg.h>` and the `va_list` type, using the `va_start`, `va_arg`, and `va_end` macros to handle a variable number of arguments of different types.
- **Underlying Hardware Architecture:** Understanding how the x86-64 System V ABI passes the first six integer/pointer arguments via registers (`%rdi`, `%rsi`, `%rdx`, `%rcx`, `%r8`, `%r9`) and spills them into a stack-allocated Register Save Area (RSA) for variadic inspection.
- **System Call Error Propagation:** Ensuring robust error handling across recursive print chains so that system call failures (`write` returning `-1`) immediately abort and propagate the error without counter corruption or undefined behavior.

### Supported Conversion Specifiers

| Specifier | Argument Type | Description |
| :--- | :--- | :--- |
| `%c` | `int` (promoted `char`) | Prints a single character (handles null byte `'\0'` cleanly). |
| `%s` | `char *` | Prints a string of characters (prints `(null)` if pointer is `NULL`). |
| `%p` | `void *` / `unsigned long` | Prints a pointer memory address in lowercase hex prefixed with `0x` (or `(nil)` on Linux for `NULL`). |
| `%d` / `%i` | `int` | Prints a signed decimal integer (handles `INT_MIN` safely). |
| `%u` | `unsigned int` | Prints an unsigned decimal number. |
| `%x` | `unsigned int` | Prints an unsigned number in lowercase hexadecimal (`0123456789abcdef`). |
| `%X` | `unsigned int` | Prints an unsigned number in uppercase hexadecimal (`0123456789ABCDEF`). |
| `%%` | None | Prints a literal percent character (`%`). |

---

## Algorithm and Data Structure Justification

### 1. Architectural Choice: Direct Output vs. Buffer Management
* **Subject Specification:** In accordance with the 42 subject guidelines, the internal buffering mechanism of standard `libc` (`stdio` stream buffers) is omitted.
* **Design Decision:** The implementation writes directly to standard output (`stdout`, file descriptor 1) using `write(2)`. While this incurs more frequent system calls than an internal 4096-byte staging buffer, it eliminates dynamic heap allocation (`malloc`/`free`) and guarantees zero memory leak risk, immediate stream delivery, and an exceptionally small memory footprint.

### 2. Parsing Architecture: Double-Pointer Format Traversal
* **Problem:** Each conversion specifier requires advancing the format string pointer past `%` and the specifier character. Returning separate index values or managing indices creates excessive local variables that trigger 42 Norminette violations (exceeding 25 lines or 4 local variables).
* **Chosen Solution:** `ft_printf` passes the address of the format string pointer (`const char **format`) to a dedicated dispatcher function (`handle_spec`). By executing `(*format)++` by reference:
  - The caller's format pointer advances in-place.
  - Trailing percent edge cases (e.g., `ft_printf("%%%")`) are caught at parser boundaries: if `!**format` is detected immediately after `%`, the parser stops, cleans up variadic registers via `va_end`, and returns `-1` without reading past the null terminator `\0`.

### 3. Number Formatting: Recursive Stack-Based Traversal
* **Algorithm:** Numeric conversions (`ft_putnbr`, `ft_putunbr`, `ft_puthex`, `ft_putptr`) use **recursion** rather than heap allocation (`malloc`/`itoa`) or fixed temporary arrays.
* **Justification:**
  - **Natural Digit Ordering:** Base conversion naturally produces least-significant digits first (via modulo `% 10` or `% 16`). Recursive descent processes the quotient first, reversing the order on the call stack unwinding so digits print from most-significant to least-significant without allocating an intermediate string buffer.
  - **Memory Efficiency & Norm Compliance:** By reusing the runtime execution stack, functions require only two local variables (`long nb`, `int count`), keeping every routine well under the 25-line limit.
  - **Robust Error Bubble-Up:** Every recursive return value is checked: if a write fails (`ret == -1`), the call stack unwinds immediately and returns `-1` to the top-level caller without executing subsequent writes.

### 4. Integer Boundary Handling
* `INT_MIN` (`-2147483648`) cannot be negated inside a 32-bit signed integer because its absolute value exceeds `INT_MAX` (`2147483647`), causing undefined integer overflow.
* **Justification:** The value is immediately widened to an 8-byte `long` prior to negation (`nb = -nb`), allowing seamless formatting of `INT_MIN` without special-case branches.

---

## Instructions

### Compilation

The project is compiled into a static library named `libftprintf.a` using a Makefile. The compilation follows strict compiler flags: `-Wall -Wextra -Werror`.

To compile the library:
```bash
make
```

Makefile targets:
* `make` or `make all` — Compiles source files and archives them into `libftprintf.a`.
* `make clean` — Removes intermediate object files (`.o`).
* `make fclean` — Removes object files and `libftprintf.a`.
* `make re` — Performs a complete rebuild (`fclean` followed by `all`).

### Linking and Usage

To use `ft_printf` in a C application:

1. Include the header in your C source files:
   ```c
   #include "ft_printf.h"
   ```

2. Compile your program by linking against `libftprintf.a`:
   ```bash
   cc -Wall -Wextra -Werror main.c -L. -lftprintf -o my_program
   ```
   *Alternatively, compile directly with the archive file:*
   ```bash
   cc -Wall -Wextra -Werror main.c libftprintf.a -o my_program
   ```

---

## Resources & AI Usage

### Classic References & Documentation
- **Linux Programmer’s Manual (`man` pages):**
  - `man 3 printf` — Standard formatted output conversion.
  - `man 3 stdarg` — Variable argument lists (`va_list`, `va_start`, `va_arg`, `va_end`).
  - `man 2 write` — Direct kernel output system call.
- **System V Application Binary Interfacex86-64TM Architecture Processor SupplementDraft Version 0.21**

- **Variadic Functions in C** `geeksforgeeks`.

### Description of AI Usage
In accordance with 42 curriculum regulations regarding generative AI, AI assistance was utilized transparently for discover **Low-Level Architecture Analysis** Gaining deep theoretical understanding of the x86-64 System V ABI, specifically how hardware registers (`%rdi`, `%rsi`, `%rdx`, etc.) are spilled into the stack-allocated Register Save Area and traversed by the internal `va_list` structure.
