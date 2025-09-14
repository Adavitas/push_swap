/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_lw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobu <nobu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 21:18:04 by nobu              #+#    #+#             */
/*   Updated: 2025/07/05 01:56:13 by nobu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex_lw(unsigned long nbr, size_t *counter)
{
	if (nbr > 15)
		ft_putnbr_hex_lw(nbr / 16, counter);
	nbr = nbr % 16;
	if (nbr < 10)
		ft_putchar_p(nbr + 48, counter);
	else
		ft_putchar_p(nbr + 87, counter);
}
