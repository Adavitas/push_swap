/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_up.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobu <nobu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:44:34 by nobu              #+#    #+#             */
/*   Updated: 2025/07/05 02:02:54 by nobu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex_up(unsigned long nbr, size_t *counter)
{
	if (nbr > 15)
		ft_putnbr_hex_up(nbr / 16, counter);
	nbr = nbr % 16;
	if (nbr < 10)
		ft_putchar_p(nbr + 48, counter);
	else
		ft_putchar_p(nbr + 55, counter);
}
