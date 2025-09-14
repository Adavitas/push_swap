/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobu <nobu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 18:14:09 by nobu              #+#    #+#             */
/*   Updated: 2025/07/05 02:03:40 by nobu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_p(const char *str, va_list ap, size_t *counter)
{
	if (*str == 'c')
		ft_putchar_p(va_arg(ap, int), counter);
	else if (*str == 's')
		ft_putstr_p(va_arg(ap, char *), counter);
	else if (*str == 'd' || *str == 'i')
		ft_putnbr_p((long)(va_arg(ap, int)), counter);
	else if (*str == 'u')
		ft_putnbr_p((long)(va_arg(ap, unsigned int)), counter);
	else if (*str == 'p')
		ft_putptr_p(va_arg(ap, void *), counter);
	else if (*str == 'x')
		ft_putnbr_hex_lw((unsigned long)(va_arg(ap, unsigned int)), counter);
	else if (*str == 'X')
		ft_putnbr_hex_up((unsigned long)(va_arg(ap, unsigned int)), counter);
	else if (*str == '%')
		ft_putchar_p('%', counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	counter;

	if (!str)
		return (0);
	counter = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_format_p(str, ap, &counter);
		}
		else
			ft_putchar_p((char)*str, &counter);
		str++;
	}
	va_end(ap);
	return (counter);
}
