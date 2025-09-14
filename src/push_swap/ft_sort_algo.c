#include "push_swap.h"

static void ft_sort_end(t_list **a, t_list **b, int max_b, int max_a)
{
    t_list *last;

    last = ft_last_node(*a);
    if (last && last->rank > max_b && last->rank != max_a)
    {
        rra(a);
        ft_sort_end(a, b, max_b, max_a);
    }
}

static void ft_revpush_a(t_list **a, t_list **b, int cur_chunk, int *count)
{
    int max_a;
    t_list *last_a;

    max_a = ft_max_rank(*a);
    last_a = ft_last_node(*a);
    if (*b && (*b)->rank == ft_max_rank(*b))
    {
        pa(a, b);
        ft_sort_end(a, b, ft_max_rank(*b), max_a);
        (*count)--;
        if (*count)
            rrb(b);
    }
    else if (*b && (last_a->rank == max_a || last_a->rank < (*b)->rank))
    {
        pa(a, b);
        ra(a);
        (*count)--;
        if (*b && ft_last_node(*b)->rank >= cur_chunk && (*b)->rank < cur_chunk)
            rrb(b);
    }
    else
        rrb(b);
}

void ft_rev_b(t_list **a, t_list **b, int cur_chunk, int *count)
{
    rrb(b);
    while(*count)
    {
        ft_revpush_a(a, b, cur_chunk, count);
        if (*count && *b && (*b)->rank < cur_chunk)
        {
            rb(b);
            ft_push_a(a, b, cur_chunk, count);
        }
    }
}

void ft_push_a(t_list **a, t_list **b, int cur_chunk, int *count)
{
    int max_a;
    t_list *last_a;

    max_a = ft_max_rank(*a);
    while (*count && *b && *a)
    {
        last_a = ft_last_node(*a);
        if ((*b)->rank == ft_max_rank(*b))
        {
            pa(a, b);
            ft_sort_end(a, b, ft_max_rank(*b), max_a);
            (*count)--;
        }
        else if (last_a->rank == max_a || last_a->rank < (*b)->rank)
        {
            pa(a, b);
            ra(a);
            (*count)--;
        }
        else
            rb(b);
        if (*count && *b && (*b)->rank < cur_chunk)
            ft_rev_b(a, b, cur_chunk, count);
    }
}