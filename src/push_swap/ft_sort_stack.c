/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitas <adavitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:58:38 by adavitas          #+#    #+#             */
/*   Updated: 2025/09/15 15:32:52 by adavitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_a(t_list **a, t_list **b, int *chunks, int chunk_count)
{
	int	index;
	int	count;
	int	chunk_b;

	index = 0;
	while (index < chunk_count)
	{
		if (index + 1 < chunk_count)
			count = (chunks[index] - chunks[index + 1]) / 2 + (chunks[index]
					- chunks[index + 1]) % 2;
		else
			count = chunks[index] / 2 + chunks[index] % 2;
		chunk_b = chunks[index] - count;
		ft_push_a(a, b, chunk_b + 1, &count);
		if (index + 1 < chunk_count)
			count = (chunks[index] - chunks[index + 1]) / 2;
		else
			count = chunks[index] / 2;
		index++;
		if (index >= chunk_count)
			break ;
		ft_rev_b(a, b, chunks[index] + 1, &count);
	}
	count = ft_stack_len(*b);
	ft_push_a(a, b, 1, &count);
}

static void	ft_make_b(t_list **a, t_list **b, int *chunks, int chunk_count)
{
	int	count;
	int	chunk_b;
	int	prev_chunk;

	count = 0;
	chunk_b = 0;
	prev_chunk = 0;
	while (chunk_count--)
	{
		count = chunks[chunk_count] - prev_chunk;
		chunk_b = (count / 2) + prev_chunk;
		while (count && *a)
		{
			if ((*a)->rank <= chunks[chunk_count] && (*a)->rank > prev_chunk)
			{
				pb(a, b);
				if (*b && (*b)->rank <= chunk_b)
					rb(b);
				count--;
			}
			else
				ra(a);
		}
		prev_chunk = chunks[chunk_count];
	}
}

void	ft_sort_stack(t_list **a, t_list **b)
{
	int	len_a;
	int	*chunks;
	int	chunk_count;

	len_a = ft_stack_len(*a);
	chunk_count = ft_chunk_count(len_a);
	chunks = ft_chunks(len_a, chunk_count);
	ft_make_b(a, b, chunks, chunk_count);
	ft_sort_five(a, b);
	ft_sort_a(a, b, chunks, chunk_count);
	while (ft_last_node(*a)->rank < (*a)->rank)
		rra(a);
	free(chunks);
}
