/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitas <adavitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:58:45 by adavitas          #+#    #+#             */
/*   Updated: 2025/09/15 15:26:17 by adavitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_init_stack(t_list **stack, char **argv)
{
	int		index;
	t_list	*node;

	index = 0;
	while (argv[index])
	{
		node = ft_new_node(ft_atoi(argv[index]));
		ft_node_to_stack(stack, node);
		index++;
	}
	ft_init_rank(stack);
}

static void	ft_sort(t_list **a, t_list **b)
{
	if (!ft_check_sorted(a))
	{
		if (ft_stack_len(*a) == 2)
			sa(a);
		else if (ft_stack_len(*a) == 3)
			ft_sort_three(a);
		else
			ft_sort_stack(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	**arr;

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
	if (argc == 2)
		ft_free_string(arr);
	ft_sort(&a, &b);
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}
