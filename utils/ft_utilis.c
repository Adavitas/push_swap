/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitas <adavitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:59:03 by adavitas          #+#    #+#             */
/*   Updated: 2025/09/15 14:59:04 by adavitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_err(char *err)
{
	ft_printf("%s\n", err);
	exit(0);
}

void	ft_free_string(char **arr)
{
	int	index;

	index = 0;
	while (arr[index])
	{
		free(arr[index]);
		index++;
	}
	free(arr);
}

void	ft_free_stack(t_list **stack)
{
	t_list	*node;

	node = *stack;
	while (*stack)
	{
		node = (*stack)->next;
		free(*stack);
		*stack = node;
	}
}
