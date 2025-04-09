
#ifndef VOXETTE_BASE_ALLOCATORS_H
#define VOXETTE_BASE_ALLOCATORS_H

#include <stdbool.h>
#include <stdint.h>

typedef struct VxPool VxPool;
typedef struct VxArena VxArena;

struct VxArena
{
    uint32_t capacity;
    uint32_t usage;
    void *allocation;

    VxArena *continuation;
};

struct VxPool
{
    uint32_t usage;
    uint32_t capacity;
    uint32_t item_size;
    void *allocation;
    void *first_free;

    VxPool *continuation;
};

// ==> Arena

VxArena * vx_new_arena(uint32_t capacity);
void vx_free_arena(VxArena *arena);

void * vx_arena_alloc(VxArena *arena, uint32_t length);
char * vx_arena_copy_string(VxArena *arena, const char *string);

void vx_reset_arena(VxArena *arena, uint32_t max_allocations);
uint32_t vx_count_arena_allocations(VxArena *arena);

void * vx_arena_or_malloc(VxArena *arena, uint32_t length);

// ==> Pool

VxPool * vx_new_pool(uint32_t item_size, uint32_t capacity);
void vx_free_pool(VxPool *pool);

void *vx_pool(VxPool *pool);
void vx_unpool(void *allocation);

#endif // VOXETTE_BASE_ALLOCATORS_H

