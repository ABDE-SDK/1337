_This project has been created as part of the 42 curriculum by asidki._

# Libft

## Description

**Libft** is my first own C library. The goal of the project is to understand how the standard C library works by re-implementing a set of its functions from scratch, then extending them with additional utility functions and a small linked-list. The result is a static library, `libft.a`, that can be reused in later projects of the 42 curriculum.

The project is split into three parts:

1. **Libc functions**: re-implementations of standard functions, with the same prototypes and behaviour as the originals but prefixed with `ft_`.
2. **Additional functions**: string, number and file-descriptor helpers that are either missing from the libc or exist in a different form.
3. **Linked list**: a generic singly linked list (`t_list`) with functions to create, modify, iterate over, map and free lists.

### Constraints

- Written in C, following the 42 Norm.
- Compiled with `cc -Wall -Wextra -Werror`.
- No global variables.
- Helper functions are declared `static`.
- The library is built with `ar` (`libtool` is forbidden) and is created at the root of the repository.
- No memory leaks, no unexpected crashes (except for undefined behaviour).

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
git clone <your-repository-url> libft
cd libft
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

## Library description

### Part 1 - Libc functions

| Category              | Functions                                                                                   |
|-----------------------|---------------------------------------------------------------------------------------------|
| Character checks      | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` (return `1` or `0`)    |
| Character conversion  | `ft_toupper`, `ft_tolower`                                                                  |
| Memory                | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`                |
| Strings               | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr` |
| Conversion            | `ft_atoi`                                                                                   |
| Allocation (`malloc`) | `ft_calloc`, `ft_strdup`                                                                    |

Note: if `nmemb` or `size` is `0`, `ft_calloc` returns a unique pointer that can be passed to `free()`.

### Part 2 - Additional functions

| Function          | Description                                                                 |
|-------------------|-----------------------------------------------------------------------------|
| `ft_substr`       | Returns a substring of `s` starting at `start`, of at most `len` characters |
| `ft_strjoin`      | Returns a new string made of `s1` followed by `s2`                          |
| `ft_strtrim`      | Returns a copy of `s1` without the characters of `set` at both ends         |
| `ft_split`        | Splits `s` using `c` as delimiter into a NULL-terminated array of strings   |
| `ft_itoa`         | Converts an integer (including negatives) to a string                       |
| `ft_strmapi`      | Applies `f(index, char)` to each character and returns the new string       |
| `ft_striteri`     | Applies `f(index, char *)` to each character of `s` in place                |
| `ft_putchar_fd`   | Writes a character to a file descriptor                                     |
| `ft_putstr_fd`    | Writes a string to a file descriptor                                        |
| `ft_putendl_fd`   | Writes a string followed by a newline to a file descriptor                  |
| `ft_putnbr_fd`    | Writes an integer to a file descriptor                                      |

### Part 3 - Linked list

The list uses the following structure, declared in `libft.h`:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

| Function          | Description                                                                  |
|-------------------|------------------------------------------------------------------------------|
| `ft_lstnew`       | Creates a new node holding `content`, with `next` set to `NULL`              |
| `ft_lstadd_front` | Adds a node at the beginning of the list                                     |
| `ft_lstsize`      | Counts the nodes in the list                                                 |
| `ft_lstlast`      | Returns the last node of the list                                            |
| `ft_lstadd_back`  | Adds a node at the end of the list                                           |
| `ft_lstdelone`    | Frees one node's content with `del`, then the node itself                    |
| `ft_lstclear`     | Frees a node and all its successors, then sets the list pointer to `NULL`    |
| `ft_lstiter`      | Applies `f` to the content of each node                                      |
| `ft_lstmap`       | Builds a new list from the results of `f`, using `del` to clean up on failure |

### Repository layout

```
.
├── Makefile
├── README.md
├── libft.h
└── ft_*.c
```

## Resources

### References

- `man 3` pages for each re-implemented function (`man 3 strlen`, `man 3 memmove`, etc.)
- [Head First C](https://www.oreilly.com/library/view/head-first-c/9781449335649/), by David Griffiths, Dawn Griffiths
- [Memory Layout of C Programs](https://www.geeksforgeeks.org/c/memory-layout-of-c-program/) geeksforgeeks
- [Learn Makefiles](https://makefiletutorial.com/) Makefile Tutorial
- `man 1 ar` for building static libraries
- The 42 Norm

### Use of AI

AI was used to help me understand important concepts required for this project, including Makefiles, C structures, pointers, and linked lists. I also used AI to explore edge cases, understand expected function behavior, and identify possible issues in my implementations.

AI was not used to generate the complete project code. I tried to write the code myself and solve problems independently. When I encountered errors or difficulties, I first asked my peers for help or searched for solutions and explanations on Stack Overflow. If I could not find a suitable explanation, I used AI to get hints, clarify concepts, and understand possible approaches rather than asking for the correct code directly.

The goal of using AI was to improve my understanding of C programming, strengthen my problem-solving skills, and learn how to handle edge cases independently.