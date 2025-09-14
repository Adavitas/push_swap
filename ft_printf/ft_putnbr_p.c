/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobu <nobu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:40:27 by nobu              #+#    #+#             */
/*   Updated: 2025/07/05 02:00:52 by nobu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_p(long nbr, size_t *counter)
{
	if (nbr < 0)
	{
		ft_putchar_p('-', counter);
		nbr = -nbr;
	}
	if (nbr > 9)
		ft_putnbr_p(nbr / 10, counter);
	ft_putchar_p((nbr % 10) + 48, counter);
}
