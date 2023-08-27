#include "monty.h"
/**
 * _calloc - concatenate two strings 
 * @numel: number of elements
 * @size: type of elements
 * Return: nothing
 */
void *_calloc(unsigned int numel, unsigned int size)
{
    void *p = NULL;
    unsigned int n;

    if (numel == 0 || size == 0)
    {
        return (NULL);
    }

    p = malloc(numel * size);
    if (p == NULL)
    {
        return (NULL);
    }
    for (n = 0; n < (numel * size); n++)
    {
        *((char *)(p) + n) = 0;
    }
    return (p);
}

/**
 * _realloc - change the size and copy the content
 * @ptr: malloc pointer to reallocate
 * @old_size: old number of bytes
 * @new_size: new number of bytes
 * Return: nothing
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    char *p = NULL;
    unsigned int n;

    if (new_size == old_size)
        return (ptr);
    if (ptr == NULL)
    {
        p = malloc(new_size);
        if (!p)
                return (NULL);
        return (p);
    }
    if (new_size == 0 && ptr != NULL)
    {
        free(ptr);
        return (NULL);
    }
    if (new_size > old_size)
    {
        p = malloc(new_size);
        if (!p)
                return (NULL);
        for (n = 0; n < new_size; n++)
                p[n] = *((char *)ptr + n);
        free(ptr);
    }
    return (p);
}
