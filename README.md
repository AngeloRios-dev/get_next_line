# get_next_line
The goal of this project is simple: program a function that returns a line read from a file descriptor.

## read_until_new_line

Description:  
`read_until_new_line` is a helper function responsible for reading data from a file descriptor (`fd`) in blocks of size `BUFFER_SIZE` until a newline character (`\n`) is found or the end of the file is reached. Its purpose is to progressively accumulate data without reading more than necessary, storing it in an intermediate stash that can be reused across multiple calls to `get_next_line`.

Key Features:

   - Uses `read()` in a loop controlled by the presence of `\n` in the stash.

   - Returns `NULL` if a read or memory allocation error occurs.

   - Returns a new updated stash with both previously read content and the newly read data.


## append_buffer

Description:  
`ft_append_buffer` concatenates the current contents of the stash with the new data read from the buffer, ensuring proper memory allocation and freeing the previous memory. It is a helper function that encapsulates safe dynamic concatenation logic.

Key Features:

   - Properly null-terminates the buffer (`\0`) before concatenation.

   - Frees the previous stash to prevent memory leaks.

   - Returns the new stash resulting from the merge, or `NULL` in case of failure.


## trim_stash

Description:  
`trim_stash` is responsible for removing the already read line from the stash (up to and including the `\n`), returning a copy of the remaining content. If there's no more useful content, it frees the stash and returns `NULL`.

