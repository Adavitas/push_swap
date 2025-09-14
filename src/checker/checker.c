#include "checker.h"

static void	ft_print_free(t_list **a, t_list **b)
{
	if (ft_check_sorted(a) && !*b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free_stack(a);
	ft_free_stack(b);
}

static void ft_get_operations(t_list **a, t_list **b)
{
    char *line;

    line = NULL;
    while ((line = get_next_line(0)))
    {
        if (ft_operations_check(line, a, b))
        {
            free(line);
            ft_err("Error");
        }
        else
            free(line);
    }
}

static void ft_init_stack(t_list **stack, char **argv)
{
    int index;
    t_list *node;

    index = 0;
    while (argv[index])
    {
        node = ft_new_node(ft_atoi(argv[index]));
        ft_node_to_stack(stack, node);
        index++;
    }
    ft_init_rank(stack);
}

int main(int argc, char **argv)
{
    t_list *a;
    t_list *b;
    char    **arr;

    a = NULL;
    b = NULL;
    arr = NULL;
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return (1);
    else if (argc == 2)
        arr = ft_split(argv[1], ' ');
    else
        arr = argv + 1;
    ft_check_err(arr);
    ft_init_stack(&a, arr);
    ft_get_operations(&a, &b);
    if (argc == 2)
    {
        ft_free_string(arr);
    }
    ft_print_free(&a, &b);
    return (0);
}
