/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_err.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitas <adavitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:58:48 by adavitas          #+#    #+#             */
/*   Updated: 2025/09/15 15:26:59 by adavitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	ft_check_dup(char **arr, int nbr, int index)
{
	while (arr[index])
	{
		if (ft_atoi(arr[index]) == nbr)
			return (1);
		index++;
	}
	return (0);
}

static int	ft_check_nbr(char *nbr)
{
	int	index;

	index = 0;
	if (nbr[index] == '-')
		index++;
	while (nbr[index])
	{
		if (!ft_isdigit(nbr[index]))
			return (1);
		index++;
	}
	return (0);
}

void	ft_check_err(char **argv)
{
	int		index;
	char	**arr;
	int		nbr;

	index = 0;
	arr = argv;
	while (arr[index])
	{
		if (ft_check_nbr(arr[index]))
			ft_err("Error");
		nbr = ft_atoi(arr[index]);
		if (arr[index + 1])
		{
			if (ft_check_dup(arr, nbr, index + 1))
				ft_err("Error");
		}
		index++;
	}
}
