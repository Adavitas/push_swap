#include "checker.h"

static void remove_trailing_newline(char *s)
{
    size_t i;

    if (!s)
        return;
    i = 0;
    while (s[i])
        i++;
    if (i > 0 && s[i - 1] == '\n')
        s[i - 1] = '\0';
}

static int ft_swap_push(char *line, t_list **a, t_list **b)
{
    if (!ft_strcmp(line, "sa"))
        return (swap(a), 1);
    if (!ft_strcmp(line, "sb"))
        return (swap(b), 1);
    if (!ft_strcmp(line, "ss"))
        return (swap(a), swap(b), 1);
    if (!ft_strcmp(line, "pa"))
        return (push(b, a), 1);
    if (!ft_strcmp(line, "pb"))
        return (push(a, b), 1);
    return (0);
}

static int ft_rotate(char *line, t_list **a, t_list **b)
{
    if (!ft_strcmp(line, "ra"))
        return (rotate(a), 1);
    if (!ft_strcmp(line, "rb"))
        return (rotate(b), 1);
    if (!ft_strcmp(line, "rr"))
        return (rotate(a), rotate(b), 1);
    if (!ft_strcmp(line, "rra"))
        return (reverse_rotate(a), 1);
    if (!ft_strcmp(line, "rrb"))
        return (reverse_rotate(b), 1);
    if (!ft_strcmp(line, "rrr"))
        return (reverse_rotate(a), reverse_rotate(b), 1);
    return (0);
}

int ft_operations_check(char *line, t_list **a, t_list **b)
{
    if (!line)
        return (1);
    remove_trailing_newline(line);
    if (ft_swap_push(line, a, b))
        return (0);
    if (ft_rotate(line, a, b))
        return (0);
    return (1);
}
