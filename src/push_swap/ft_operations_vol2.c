/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_vol2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitas <adavitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:58:22 by adavitas          #+#    #+#             */
/*   Updated: 2025/09/15 15:24:30 by adavitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_list **a)
{
	if (!rotate(a))
		return (1);
	ft_printf("ra\n");
	return (0);
}

int	rb(t_list **b)
{
	if (!rotate(b))
		return (1);
	ft_printf("rb\n");
	return (0);
}

int	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*before_last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	before_last = *stack;
	while (before_last->next && before_last->next->next)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
	return (1);
}

int	rra(t_list **a)
{
	if (!reverse_rotate(a))
		return (1);
	ft_printf("rra\n");
	return (0);
}

int	rrb(t_list **b)
{
	if (!reverse_rotate(b))
		return (1);
	ft_printf("rrb\n");
	return (0);
}
