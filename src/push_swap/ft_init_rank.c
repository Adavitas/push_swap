#include "push_swap.h"

static t_list *ft_min_node(t_list **stack)
{
    t_list *first;
    t_list *lowest;
    
    first = *stack;
    lowest = NULL;
    while (first)
    {
        if (first->rank == 0 && (lowest == NULL || first->nbr < lowest->nbr))
            lowest = first; 
        first = first->next;
    }
    return (lowest);
}

void    ft_init_rank(t_list **stack)
{
    t_list *first;
    int rank;

    first = ft_min_node(stack);
    rank = 1;
    while (first)
    {
        first->rank = rank;
        first = ft_min_node(stack);
        rank++;
    }
} 