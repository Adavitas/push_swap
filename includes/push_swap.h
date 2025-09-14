#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include "utils.h"
#include "ft_printf.h"

typedef struct s_list
{
    int             nbr;
    int             rank;
    struct s_list   *next;
}   t_list;


void    ft_sort_three(t_list **stack);
void ft_sort_five(t_list **a, t_list **b);
void    ft_sort_stack(t_list **a, t_list **b);

void ft_push_a(t_list **a, t_list **b, int cur_chunk, int *count);
void ft_rev_b(t_list **a, t_list **b, int cur_chunk, int *count);

int ft_max_rank(t_list *stack);
int     ft_check_sorted(t_list **stack);
void    ft_init_rank(t_list **stack);
int ft_chunk_count(int size);
int *ft_chunks(int size, int count);

int sa(t_list **a);
int sb(t_list **b);
int pa(t_list **a, t_list **b);
int pb(t_list **a, t_list **b);
int ra(t_list **a);
int rb(t_list **b);
int rra(t_list **a);
int rrb(t_list **b);

int	swap(t_list **stack);
int push(t_list **src, t_list **dst);
int rotate(t_list **stack);
int reverse_rotate(t_list **stack);

#endif