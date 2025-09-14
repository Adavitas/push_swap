#include "push_swap.h"

int	swap(t_list **stack)
{
    t_list	*first;
    t_list	*next;
    int		nbr;
    int		rank;

    if (!stack || !*stack || !(*stack)->next)
        return (0);
    first = *stack;
    next = first->next;
    nbr = first->nbr;
    rank = first->rank;
    first->nbr = next->nbr;
    first->rank = next->rank;
    next->nbr = nbr;
    next->rank = rank;
    return (1);
}

int sa(t_list **a)
{
    if (!swap(a))
        return (1);
    ft_printf("sa\n");
    return (0);
}

int sb(t_list **b)
{
    if (!swap(b))
        return (1);
    ft_printf("sb\n");
    return (0);
}
