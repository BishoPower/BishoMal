#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

#define HEAP_CAP 640000
#define HEAP_ALLOCED_CAP 1024
#define HEAP_FREED_CAP 1024

typedef struct
{
    void *start;
    size_t size;
} Chunk;

typedef struct {
    size_t size;
    Chunk chunks[HEAP_ALLOCED_CAP];
} Chunk_List;

int chunk_list_find(const Chunk_List *list, void *ptr)
{
    assert(false && "TODO: chunk_list_find is not implemented");
    return -1;
}

void chunk_list_insert(Chunk_List *list, void *ptr, size_t size)
{
    assert(false && "TODO: chunk_list_insert is not implemented");
}

void chunk_list_remove(Chunk_List *list, size_t index)
{
    assert(false && "TODO: chunk_list_remove is not implemented");
}

char heap[HEAP_CAP] = {0};
size_t heap_size = 0;

Chunk_List alloced_chunks = {0};
Chunk_List freed_chunks = {0};

void *heap_alloc(size_t size)
{
    if (size > 0)
    {
        assert(heap_size + size <= HEAP_CAP);
        void *free_ptr = heap + heap_size;
        heap_size += size;

        Heap_Chunk chunk = {
            .start = free_ptr,
            .size = size,
        };

        assert(heap_alloced_size < HEAP_ALLOCED_CAP);
        heap_alloced[heap_alloced_size++] = chunk;

        return free_ptr;
    }
    else
    {
        return NULL;
    }
}

void heap_dump_alloced_chunks(void)
{
    printf("Allocated Chunks (%zu):\n", heap_alloced_size);
    for (size_t i = 0; i < heap_alloced_size; ++i)
    {
        Heap_Chunk chunk = heap_alloced[i];
        printf("  start: %p, size: %zu\n", chunk.start, chunk.size);
    }
}

void heap_free(void *ptr)
{
    for (size_t i = 0; i < heap_alloced_size; ++i)
    {
        if (heap_alloced[i].start == ptr)
        {
        }
    }

    (void)ptr;
    assert(false && "heap_free not implemented");
}

void heap_collect()
{
    assert(false && "heap_collect not implemented");
}

int main()
{
    for (int i = 0; i < 100; ++i)
    {
        void *p = heap_alloc(i);
        if (i % 2 == 0)
        {
            heap_free(p);
        }
    }

    heap_dump_alloced_chunks();

    return 0;
}