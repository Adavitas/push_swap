/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_vol1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitas <adavitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:58:19 by adavitas          #+#    #+#             */
/*   Updated: 2025/09/15 14:58:21 by adavitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_list **src, t_list **dst)
{
	t_list	*node;

	if (!src || !*src)
		return (0);
	node = *src;
	*src = node->next;
	node->next = *dst;
	*dst = node;
	return (1);
}

int	pa(t_list **a, t_list **b)
{
	if (!push(b, a))
		return (1);
	ft_printf("pa\n");
	return (0);
}

int	pb(t_list **a, t_list **b)
{
	if (!push(a, b))
		return (1);
	ft_printf("pb\n");
	return (0);
}

int	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	return (1);
}
