*This project has been created as part of the 42 curriculum by asidki.*

# get_next_line

## Description
`get_next_line` is a programming project from the 42 curriculum. The goal of this project is to write a C function that reads and returns a single line from a file descriptor (`fd`) each time it is called.

Whether reading from a standard file or standard input, `get_next_line` preserves unread bytes in static memory so that consecutive calls smoothly retrieve lines one after another until the End-Of-File (EOF) is reached. The bonus part extends this functionality to handle reading from **multiple file descriptors simultaneously** without mixing or losing buffer data.

## Algorithm Explanation & Justification

### Selected Algorithm: Static Linked List Buffer Management
The project uses a single static linked list (`t_list *head_stash`) where each node stores a file descriptor (`fd`) and its corresponding unread buffer (`stash`).

1. **Node Lookup & Creation:** When `get_next_line(fd)` is called, it searches the linked list for a node matching `fd`. If no node exists yet, a new node is allocated and added to the list.
2. **Reading & Concatenation:** `read_until_nl` reads chunks of size `BUFFER_SIZE` into a temporary buffer and appends (`ft_strjoin`) them to `node->stash` until a newline (`\n`) is encountered or `read()` returns `0` (EOF) / `-1` (error).
3. **Line Extraction & Stash Trimming:** `clean_line_and_save_remain` extracts the line up to `\n` (or `\0`) using `ft_substr`. It then backs up the old stash pointer (`line = *stash`), reallocates `*stash` with the remaining bytes, and frees the old heap memory to prevent memory leaks.
4. **Node Cleanup:** When a file descriptor reaches EOF (or encounters a read error), `free_node` unlinks the `fd` node from the linked list and frees its memory, leaving zero memory leaks.

### Justification
- **Dynamic Memory Efficiency:** Using a linked list avoids fixed-size array limits (like `OPEN_MAX`), allocating memory dynamically only for active file descriptors and freeing nodes immediately when files are completely read.
- **Leak-Free Pointer Backup:** Saving `line = *stash` before updating `*stash` ensures that old allocated blocks are freed cleanly without Use-After-Free errors.

## Instructions

### Compilation
Compile your C files with your main program, including the `BUFFER_SIZE` macro flag:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl_test
```

### Execution Example

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line_bonus.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("example.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
```

#### Multiple File Descriptors (Bonus)
```c
int	fd1 = open("file1.txt", O_RDONLY);
int	fd2 = open("file2.txt", O_RDONLY);

char *line1 = get_next_line(fd1); // Reads line 1 from file 1
char *line2 = get_next_line(fd2); // Reads line 1 from file 2

free(line1);
free(line2);
close(fd1);
close(fd2);
```

## Resources

### References
- **42 Subject PDF (`en.subject.pdf`):** Project requirements for `get_next_line`.
- **C Library Documentation:** `read(2)`, `malloc(3)`, `free(3)`, `open(2)`.

### AI Usage Declaration
`AI (Gemini Notebook)` was used during this project strictly for searching and referencing documentation, C programming concepts, and Unix system functions.
