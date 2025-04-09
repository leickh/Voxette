#include <voxette/base/allocators.h>
#include <voxette/base/math.h>

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

VxArena * vx_new_arena(uint32_t capacity)
{
    VxArena *arena = malloc(32 + capacity);
    arena->allocation = ((uint8_t *)arena) + 32;
    arena->capacity = capacity;
    arena->usage = 0;
    arena->continuation = NULL;
    return arena;
}

void vx_free_arena(VxArena *arena)
{
    if (arena->continuation)
    {
        vx_free_arena(arena->continuation);
    }
    free(arena);
}

void * vx_arena_alloc(VxArena *arena, uint32_t amount)
{
    if ((arena->usage + amount) >= arena->capacity)
    {
        if (!arena->continuation)
        {
            // Allocate a new arena that is double the size of
            // the current one, but *at least* double the size
            // of the allocation that is currently being made.
            arena->continuation = vx_new_arena(
                vx_max_i64(
                    arena->usage * 2,
                    amount * 2));
        }
        return vx_arena_alloc(
            arena->continuation,
            amount);
    }
    void *allocation = &((uint8_t *)arena->allocation)[arena->usage];
    arena->usage += amount;
    return allocation;
}

char * vx_arena_copy_string(VxArena *arena, const char *string)
{
    uint32_t len_string = strlen(string);
    char *string_copy = vx_arena_alloc(arena, len_string + 1);
    memcpy(string_copy, string, len_string + 1);
    return string_copy;
}

void vx_reset_arena(VxArena *arena, uint32_t max_allocations)
{
    // If this is the last arena that is allowed to exist, delete the
    // next one (if there is one).
    if (max_allocations == 1)
    {
        if (arena->continuation)
        {
            vx_free_arena(arena->continuation);
            arena->continuation = NULL;
        }
    }
    else if (arena->continuation)
    {
        // If another arena is allowed to exist, call this function on
        // it, but decrement the continuation count to accord for that
        // arena existing.
        vx_reset_arena(arena->continuation, max_allocations - 1);
    }
    memset(arena->allocation, 0, arena->capacity);
    arena->usage = 0;
}

uint32_t vx_count_arena_allocations(VxArena *arena)
{
    if (arena->continuation)
    {
        return vx_count_arena_allocations(arena->continuation) + 1;
    }
    return 1;
}

void * vx_arena_or_malloc(VxArena *arena, uint32_t length)
{
    if(arena == NULL)
    {
        return malloc(length);
    }
    return vx_arena_alloc(arena, length);
}

