# 📄 get_next_line
The goal of this project is simple: program a function that returns a line read from a file descriptor.

> A function that reads a line from a file descriptor, one call at a time, including the newline character (`\n`) if present.

## 🧠 Project Overview

`get_next_line` is a C function that returns one line at a time from a file descriptor. It handles reading and buffering internally, returning each line (ending with `\n` if present) with each call. It uses dynamic memory management and maintains state between calls using a static variable.

This project was developed as part of the **42 School curriculum** and focuses on mastering low-level file I/O and string operations.

---

## ⚙️ Compilation

Use `gcc` to compile the files. You can set `BUFFER_SIZE` to any positive value:

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl_test

---

# ▶️ Usage Example

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}

---

# 📁 File Structure
get_next_line/
├── get_next_line.c        # Core logic of get_next_line
├── get_next_line_utils.c  # Helper functions (string operations)
├── get_next_line.h        # Function declarations and BUFFER_SIZE macro

---

# 🔧 Functions Overview
## Main Function
- get_next_line(int fd): Reads and returns the next line from fd, including the newline character if present.

## Utility Functions
- ft_strlen: Returns the length of a string.

- ft_strchr: Searches for a character in a string.

- ft_strdup: Duplicates a string.

- ft_strjoin: Joins two strings into a new one.

- ft_substr: Extracts a substring from a string.

All utility functions are custom implementations due to project restrictions on standard library usage.