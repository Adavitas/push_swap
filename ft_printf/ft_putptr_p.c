/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobu <nobu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 21:07:02 by nobu              #+#    #+#             */
/*   Updated: 2025/07/05 02:19:51 by nobu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr_p(void *ptr, size_t *counter)
{
	unsigned long	ptr_value;

	if (ptr == NULL)
	{
		ft_putstr_p("(nil)", counter);
		return ;
	}
	ptr_value = (unsigned long)ptr;
	ft_putstr_p("0x", counter);
	ft_putnbr_hex_lw(ptr_value, counter);
}
