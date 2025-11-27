#include <constants.h>
#include <e_lib.h>

/*
 The functionality described on this reference page is
aligned with the ISO C standard. Any conflict between the requirements described
here and the ISO C standard is unintentional. This volume of IEEE Std
1003.1-2001 defers to the ISO C standard.

The free() function shall cause the space pointed to by ptr to be deallocated;
that is, made available for further allocation. If ptr is a null pointer, no
action shall occur.
*/

typedef struct Block {
  size_t size;
  int is_free; // 1 if the block is free, 0 if it is allocated
  struct Block
      *next; // Pointer to the next block in the free list (NULL if end)
} __attribute__((aligned(8))) Block;

void e_free(void *ptr) {

  if (!ptr)
    return;

  // Block header is located just before the user pointer
  Block *header = (Block *)ptr - 1;
  header->is_free = 1; // Mark as free

  // Optional: Insert logic to coalesce adjacent free blocks here, if needed
  // (not implemented in this minimal version)

  // No need to modify free_list, as it's already maintained via Block->next.
  // This is a simple free.
}
