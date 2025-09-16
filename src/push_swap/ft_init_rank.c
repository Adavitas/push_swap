/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_rank.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitas <adavitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:58:16 by adavitas          #+#    #+#             */
/*   Updated: 2025/09/15 15:23:06 by adavitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_min_node(t_list **stack)
{
	t_list	*first;
	t_list	*lowest;

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

void	ft_init_rank(t_list **stack)
{
	int		rank;
	t_list	*first;

	rank = 1;
	first = ft_min_node(stack);
	while (first)
	{
		first->rank = rank;
		first = ft_min_node(stack);
		rank++;
	}
}
