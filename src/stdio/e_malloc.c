#include <constants.h>
#include <e_lib.h>
#include <syscall.h>

// 8-byte alignment for x86_64

// initial heap allocation size if more needed (you can tune this)
// (e.g. 64K at a time is a reasonable default for tiny mallocs)
#define MALLOC_CHUNK_SIZE 65536UL
#define ALIGN8(x) ((((x) + 7) / 8) * 8)

typedef struct Block {
    size_t size;
    int is_free; // 1 if the block is free, 0 if it is allocated
    struct Block
        *next; // Pointer to the next block in the free list (NULL if end)
} __attribute__((aligned(8))) Block;
static Block *free_list = NULL;

void *e_malloc(size_t size) {
    size = ALIGN8(size);

    Block *last = NULL;
    Block *curr = free_list;

    // size align

    // search for a free block

    while (curr != NULL) {

        if (curr->is_free == 1 && curr->size >= size) {
            curr->is_free = 0;

            return (void *)(curr + 1);
        }

        last = curr;
        curr = curr->next;
    }

    // if not found, use sbrk and get some memory blocks
    void *raw_mem = sbrk(sizeof(Block) + size);

    if (raw_mem == (void *)-1) { // failed
        return NULL;
    }

    Block *header = (Block *)raw_mem;

    header->size = size;
    header->is_free = 0;
    header->next = NULL;

    if (free_list == NULL) {
        free_list = header;

    } else if (last) {
        last->next = header;
    }

    return (void *)(header + 1);

    // return a pointer to the memory
}
