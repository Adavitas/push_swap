/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobu <nobu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 01:36:15 by nobu              #+#    #+#             */
/*   Updated: 2025/08/30 05:18:01 by nobu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(char const *str, ...);

void	ft_putchar_p(char c, size_t *counter);
void	ft_putstr_p(char *str, size_t *counter);
void	ft_putnbr_p(long nbr, size_t *counter);
void	ft_putptr_p(void *ptr, size_t *counter);
void	ft_putnbr_hex_lw(unsigned long nbr, size_t *counter);
void	ft_putnbr_hex_up(unsigned long nbr, size_t *counter);

#endif