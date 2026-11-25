*This project has been created as part of the 42 curriculum by asidki.*

# get_next_line

## Description
`get_next_line` is a foundational programming project in the 42 curriculum. The primary objective is to code a C function that reads and returns a single line (terminated by a newline character `\n` or EOF `\0`) from a file descriptor (`fd`) upon each call.

The project is structured into two main components:
- **Mandatory Part:** Implements line-by-line reading from a single file descriptor using a single static string buffer (`char *stash`).
- **Bonus Part:** Extends the architecture to manage **multiple file descriptors simultaneously** without mixing, losing, or overwriting unread buffer data across calls, using a static linked list (`t_list *head_stash`).

---

## Algorithm Explanation & Justification

### Mandatory Part: Static String Buffer Algorithm
In the mandatory part, `get_next_line` retains unread data across function invocations using a single static pointer: `static char *stash`.

1. **Buffered Reading Loop (`read_until_nl`):** A temporary buffer of size `BUFFER_SIZE + 1` is allocated. The `read()` system call reads up to `BUFFER_SIZE` bytes per iteration. The buffer is null-terminated and concatenated (`ft_strjoin`) with the existing `stash` until `stash` contains a newline character (`\n`), `read()` returns `0` (EOF), or `read()` returns `-1` (read error).
2. **Line Extraction & Stash Trimming (`clean_line_and_save_remain`):** The function scans `stash` up to the first `\n` (or `\0`). It extracts the full line (including `\n` if present) into `clean_line` using `ft_substr`. It then backs up the original pointer (`line = *stash`), allocates a new string for the leftover bytes using `ft_substr`, updates `*stash`, and frees `line`. If no remaining characters exist, `*stash` is assigned `NULL`.
3. **Error & Memory Protection:** If `read()` encounters an error or `malloc` fails, any previously allocated `stash` is freed and set to `NULL` to prevent memory leaks.

#### Mandatory Algorithm Justification
- **Minimal Memory Overhead:** For single-stream reading, maintaining a single static pointer avoids the allocation overhead of dynamic list nodes.
- **Leak-Free Pointer Swap:** Storing `line = *stash` prior to reallocating `*stash` ensures that previous heap blocks are freed safely without triggering Use-After-Free or Double Free errors.

---

### Bonus Part: Static Linked List Multi-FD Algorithm
In the bonus part, `get_next_line` handles multiple open file descriptors concurrently by maintaining a static head pointer to a single-linked list: `static t_list *head_stash`. Each list node stores a file descriptor and its unread buffer:

```c
typedef struct s_list
{
	int				fd;
	char			*stash;
	struct s_list	*next;
}	t_list;
```

1. **Per-FD Node Lookup & Allocation (`get_node`):** When `get_next_line(fd)` is called, it traverses `head_stash` searching for a node matching `curr->fd == fd`. If found, that node is returned. If no node exists for the given file descriptor, a new node is allocated, initialized with `new_node->fd = fd` and `new_node->stash = NULL`, and prepended to `head_stash`.
2. **Isolated Reading (`read_until_nl`):** `read_until_nl` operates specifically on `node->stash` for the active `fd`, appending read chunks independently of other open file descriptors.
3. **Line Extraction & Stash Update:** `clean_line_and_save_remain(&node->stash)` extracts the line for the requested `fd` and updates `node->stash` with the remaining bytes for that specific descriptor.
4. **Immediate Node Unlinking & Deallocation (`free_node`):** When `node->stash` becomes `NULL` (due to reaching EOF or encountering a read error), `free_node` searches `head_stash`, unlinks the matching node from the linked list, frees `node->stash` and `node`, and updates pointer links. This guarantees zero lingering memory nodes in static space once a file reaches EOF.

#### Bonus Algorithm Justification
- **Dynamic File Descriptor Handling:** Unlike fixed-size array approaches, a linked list dynamically allocates nodes only for active file descriptors. It avoids arbitrary array size limits and scales memory consumption strictly to open files.
- **Interleaved Read Integrity:** Each file descriptor holds its own isolated `stash` buffer. Calling `get_next_line(3)`, then `get_next_line(4)`, then `get_next_line(3)` preserves the exact read offset and buffer state of both file descriptors without interference.
- **Complete Deallocation:** Unlinking and freeing nodes upon EOF ensures long-running processes do not accumulate stale node structures.

---

## Instructions

### Mandatory Part Instructions

#### Compilation
Compile the mandatory C files (`get_next_line.c`, `get_next_line_utils.c`) together with your test program, passing the `BUFFER_SIZE` macro definition:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl_mandatory
```

#### Code Example (Single File Descriptor)

```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test_mandatory.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
```

---

### Bonus Part Instructions

#### Compilation
Compile the bonus C files (`get_next_line_bonus.c`, `get_next_line_utils_bonus.c`) together with your test program, passing the `BUFFER_SIZE` macro definition:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl_bonus
```

#### Code Example (Multiple File Descriptors Interleaved)

```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*line;

	fd1 = open("file1.txt", O_RDONLY);
	fd2 = open("file2.txt", O_RDONLY);
	fd3 = open("file3.txt", O_RDONLY);

	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
		return (1);

	// Read line 1 from file 1
	if ((line = get_next_line(fd1)))
	{
		printf("FD1 Line 1: %s", line);
		free(line);
	}
	// Read line 1 from file 2
	if ((line = get_next_line(fd2)))
	{
		printf("FD2 Line 1: %s", line);
		free(line);
	}
	// Read line 1 from file 3
	if ((line = get_next_line(fd3)))
	{
		printf("FD3 Line 1: %s", line);
		free(line);
	}
	// Read line 2 from file 1
	if ((line = get_next_line(fd1)))
	{
		printf("FD1 Line 2: %s", line);
		free(line);
	}

	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
```

---

## Resources

### References
- **42 Subject PDF (`en.subject.pdf`):** Project requirements for `get_next_line`.
- **C Library Documentation:** `read(2)`, `malloc(3)`, `free(3)`, `open(2)`.


### AI Usage Declaration
AI (Gemini Notebook) was used during this project strictly for searching and referencing documentation, C programming concepts, and Unix system functions.

