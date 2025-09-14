#include "push_swap.h"

int     ft_check_sorted(t_list **stack)
{
    t_list *first;

    first = *stack;
    while (first && first->next)
    {
        if (first->rank > first->next->rank)
            return (0);
        first = first->next;
    }
    return (1);
}

int ft_max_rank(t_list *stack)
{
    int max;

    max = 0;
    while (stack)
    {
        if (stack->rank > max)
            max = stack->rank;
        stack = stack->next;
    }
    return (max);
}

int ft_chunk_count(int size)
{
    int count;
    int new_size;

    count = 0;
    new_size = size;
    while (new_size > 4)
    {
        if (size < 150)
            new_size = new_size - (new_size / 5 * 2);
        else
        {
            if (new_size < 6)
                break ;
            new_size = new_size - (new_size / 4);
        }
        count++;
    }
    return (count);
}

int *ft_chunks(int size, int count)
{
    int chunk;
    int *chunks;
    int old_chunks;
    int new_size;

    chunk = 0;
    chunks = malloc(sizeof(int) * count);
    old_chunks = 0;
    new_size = size;
    while (new_size > 4 && count > 0)
    {
        if (size < 150)
            chunk = new_size / 5 * 2;
        else
        {
            if (new_size < 6)
                break ;
            else
            chunk = new_size / 4;
        }
        new_size = new_size - chunk;
        chunk = old_chunks + chunk;
        old_chunks = chunk;
        chunks[--count] = chunk;
    }
    return (chunks);
}
