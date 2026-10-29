*This project has been created as part of the 42 curriculum by asidki.*

# Libft

## Description

**Libft** is a project from the 42 curriculum. Its goal is to create a personal C library by reimplementing several standard C library functions and developing additional utility functions.

The project helps develop a deeper understanding of C programming, memory management, pointers, strings, linked lists, and static libraries.

The library is written in C and follows the coding rules required by the 42 curriculum.

## Instructions

### Requirements

To compile and use this library, you need:

- A C compiler, such as `cc` or `gcc`.
- `make`.
- `ar` to create the static library.
- The 42 Norminette coding standard.

### Compilation

Clone the repository and enter the Libft directory:

```bash
git clone <your-repository-url>
cd <your-repository-directory>/CC/libft
```

Compile the library:

```bash
make
```

This generates the static library:

```text
libft.a
```

Available Makefile rules:

| Rule | Description |
|---|---|
| `make` or `make all` | Compile the source files and create `libft.a`. |
| `make clean` | Remove object files (`.o`). |
| `make fclean` | Remove object files and `libft.a`. |
| `make re` | Clean and rebuild the library. |

### Using the library

Include the header file in your C source file:

```c
#include "libft.h"
```

Compile your program with the library:

```bash
cc -Wall -Wextra -Werror main.c -I. -L. -lft -o program
```

Run the executable:

```bash
./program
```

Replace `main.c` with your own source file when necessary.

## Library Contents

The library contains functions that reproduce standard C library behavior and provide additional utilities.

### 1. Character Functions

These functions test or convert individual characters.

| Function | Description |
|---|---|
| `ft_isalpha` | Checks whether a character is an alphabetic letter. |
| `ft_isdigit` | Checks whether a character is a decimal digit. |
| `ft_isalnum` | Checks whether a character is alphanumeric. |
| `ft_isascii` | Checks whether a value belongs to the ASCII character set. |
| `ft_isprint` | Checks whether a character is printable. |
| `ft_toupper` | Converts a lowercase letter to uppercase. |
| `ft_tolower` | Converts an uppercase letter to lowercase. |

### 2. String Functions

These functions calculate string lengths, search strings, compare strings, and create or modify string data.

| Function | Description |
|---|---|
| `ft_strlen` | Returns the length of a string. |
| `ft_strchr` | Finds the first occurrence of a character in a string. |
| `ft_strrchr` | Finds the last occurrence of a character in a string. |
| `ft_strncmp` | Compares two strings up to a specified number of characters. |
| `ft_strlcpy` | Copies a string into a destination buffer of a specified size. |
| `ft_strlcat` | Appends a string to a destination buffer within a specified size. |
| `ft_strnstr` | Searches for a substring within a limited number of characters. |
| `ft_strdup` | Allocates memory and duplicates a string. |
| `ft_substr` | Creates a substring using a starting index and length. |
| `ft_strjoin` | Allocates and returns the concatenation of two strings. |
| `ft_strtrim` | Removes specified characters from the beginning and end of a string. |
| `ft_split` | Splits a string into an array of strings using a delimiter. |

### 3. Memory Functions

These functions operate on memory areas rather than only null-terminated strings.

| Function | Description |
|---|---|
| `ft_memset` | Fills a memory area with a specified byte value. |
| `ft_bzero` | Sets a memory area to zero. |
| `ft_memcpy` | Copies bytes between non-overlapping memory areas. |
| `ft_memmove` | Copies bytes safely when memory areas overlap. |
| `ft_memchr` | Searches for a byte in a memory area. |
| `ft_memcmp` | Compares two memory areas byte by byte. |
| `ft_calloc` | Allocates memory for an array and initializes it to zero. |

### 4. Conversion and Output Functions

| Function | Description |
|---|---|
| `ft_atoi` | Converts the initial numeric portion of a string to an integer. |
| `ft_itoa` | Converts an integer into a newly allocated string. |
| `ft_putchar_fd` | Writes a character to a specified file descriptor. |
| `ft_putstr_fd` | Writes a string to a specified file descriptor. |
| `ft_putendl_fd` | Writes a string followed by a newline to a specified file descriptor. |
| `ft_putnbr_fd` | Writes an integer to a specified file descriptor. |

### 5. Linked List Functions

The linked-list functions use the `t_list` structure defined in `libft.h`.

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

Each node stores a pointer to its content and a pointer to the next node.

| Function | Description |
|---|---|
| `ft_lstnew` | Creates a new node with the specified content. |
| `ft_lstadd_front` | Adds a node to the beginning of a list. |
| `ft_lstadd_back` | Adds a node to the end of a list. |
| `ft_lstsize` | Counts the number of nodes in a list. |
| `ft_lstlast` | Returns the last node of a list. |
| `ft_lstdelone` | Deletes one node using a supplied content-deletion function. |
| `ft_lstclear` | Deletes and frees an entire list using a supplied content-deletion function. |
| `ft_lstiter` | Applies a function to the content of each node. |
| `ft_lstmap` | Creates a new list by applying a function to each node's content. |

The linked-list functions are part of the bonus section of the project when required by the applicable Libft subject.

### Memory Management

Functions that allocate memory, such as `ft_strdup`, `ft_substr`, `ft_strjoin`, `ft_split`, `ft_itoa`, and `ft_calloc`, must be used with proper memory management.

The caller is responsible for freeing dynamically allocated memory when it is no longer needed. Linked-list deletion functions use the supplied callback to release node content where appropriate.

## Technical Choices

- **Language:** C.
- **Library type:** Static library (`libft.a`).
- **Header:** `libft.h`.
- **Compilation flags:** `-Wall -Wextra -Werror`.
- **Build system:** Makefile.
- **Coding standard:** 42 Norminette.
- **Memory management:** Dynamic allocation with functions such as `malloc` and `free`.
- **Error handling:** Functions handle applicable invalid inputs and allocation failures according to their expected behavior and project requirements.

## Testing

Compile the library:

```bash
make
```

Check the source files with Norminette:

```bash
norminette
```

You can also test the library using your own test programs or a compatible Libft tester.

For example, test string length:

```c
#include <stdio.h>
#include "libft.h"

int main(void)
{
    printf("%zu\n", ft_strlen("Hello, 1337!"));
    return (0);
}
```

Compile and run it from the Libft directory:

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o test
./test
```

## Resources

### Documentation and References

- [42 School](https://42.fr/) — Information about the 42 curriculum.
- [Linux man-pages](https://man7.org/linux/man-pages/) — Documentation for standard C library functions and system calls.
- [cppreference — C library](https://en.cppreference.com/w/c) — Reference material for the C language and its standard library.
- [GNU Compiler Collection (GCC)](https://gcc.gnu.org/onlinedocs/) — Compiler documentation.
- [GNU Make Manual](https://www.gnu.org/software/make/manual/) — Documentation for Makefiles and build automation.
- [C Programming — Beej's Guide](https://beej.us/guide/bgc/) — A practical introduction to C programming.

### AI Usage

AI tools, including ChatGPT, were used as learning and development assistance during this project.

Their use included:

- Explaining C concepts such as pointers, double pointers, structures, strings, and linked lists.
- Clarifying the expected behavior of standard library functions.
- Helping understand memory allocation, pointer manipulation, and memory deallocation.
- Assisting with debugging, interpreting compiler errors, and understanding Makefile rules.
- Reviewing implementation logic and suggesting test cases and documentation improvements.
- Helping prepare and organize this README file.

AI-generated explanations and suggestions were used as learning references. The code submitted for evaluation must be reviewed, understood, tested, and validated by the student against the official project subject and the 42 coding standards.

## Author

**ABDE-SDK** — 42 / 1337 Student

GitHub: [ABDE-SDK](https://github.com/ABDE-SDK)

