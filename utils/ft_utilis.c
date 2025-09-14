#include "utils.h"

void    ft_err(char *err)
{
    ft_printf("%s\n", err);
    exit(0);
}

void    ft_free_string(char **arr)
{
    int index;

    index = 0;
    while (arr[index])
    {
        free(arr[index]);
        index++;
    }
    free(arr);
}

void    ft_free_stack(t_list **stack)
{
    t_list *node;

    node = *stack;
    while (*stack)
    {
        node = (*stack)->next;
        free(*stack);
        *stack = node;
    }
}
