#include "push_swap.h"

void    ft_sort_three(t_list **stack)
{
    int max;

    max = ft_max_rank(*stack);
    if (max == (*stack)->rank)
        ra(stack);
    else if ((*stack)->next->rank == max)
        rra(stack);
    if ((*stack)->rank > (*stack)->next->rank)
        sa(stack);
}

static void ft_sort_four(t_list **a, t_list **b)
{
    int min;

    min = 0;
    t_list *temp = *a;
    if (ft_stack_len(*a) < 4)
    {
        ft_sort_three(a);
        return ;
    }
    while (temp)
    {
        if (temp->rank < min || min == 0)
            min = temp->rank;
        temp = temp->next;
    }
    while (*a && (*a)->rank != min)
        ra(a);
    pb(a, b);
    ft_sort_three(a);
    pa(a, b);
}

void ft_sort_five(t_list **a, t_list **b)
{
    int min;

    min = 0;
    t_list *temp = *a; 
    if (ft_stack_len(*a) < 5)
    {
        ft_sort_four(a, b);
        return ;
    }
    while (temp)
    {
        if (temp->rank < min || min == 0)
            min = temp->rank;
        temp = temp->next;
    }
    while (*a && (*a)->rank != min)
        ra(a);
    pb(a, b);
    ft_sort_four(a, b);
    pa(a, b);
}
