/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitas <adavitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:58:56 by adavitas          #+#    #+#             */
/*   Updated: 2025/09/15 15:27:52 by adavitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_list	*ft_new_node(int nbr)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->nbr = nbr;
	node->rank = 0;
	node->next = NULL;
	return (node);
}

t_list	*ft_last_node(t_list *first)
{
	if (!first)
		return (NULL);
	while (first->next)
		first = first->next;
	return (first);
}

void	ft_node_to_stack(t_list **stack, t_list *node)
{
	t_list	*last;

	if (!node)
		return ;
	node->next = NULL;
	if (*stack)
	{
		last = ft_last_node(*stack);
		last->next = node;
	}
	else
		*stack = node;
}

int	ft_stack_len(t_list *first)
{
	t_list	*node;
	int		index;

	node = first;
	index = 0;
	while (node)
	{
		node = node->next;
		index++;
	}
	return (index);
}
