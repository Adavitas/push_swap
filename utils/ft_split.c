/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitas <adavitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:58:59 by adavitas          #+#    #+#             */
/*   Updated: 2025/09/15 15:28:27 by adavitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_strlcpy(char *dst, char *src, int size)
{
	int	len;

	len = ft_strlen(src);
	if (dst == NULL || src == NULL || !size)
		return (len);
	while (*src && --size)
		*dst++ = *src++;
	*dst = '\0';
	return (len);
}

static int	count_words(char *s, char c)
{
	int	w;

	w = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			w++;
		while (*s && *s != c)
			s++;
	}
	return (w);
}

static char	*next_word(char **s, char c)
{
	char	*start;
	int		len;
	char	*word;

	while (**s == c)
		(*s)++;
	start = *s;
	while (**s && **s != c)
		(*s)++;
	len = *s - start;
	word = malloc(len + 1);
	if (word)
		ft_strlcpy(word, start, len + 1);
	return (word);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		w;
	char	**res;

	if (!s)
		return (NULL);
	i = 0;
	w = count_words(s, c);
	res = malloc((w + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (i < w)
	{
		res[i] = next_word(&s, c);
		if (!res[i])
		{
			while (i > 0)
				free(res[--i]);
			free(res);
			return (NULL);
		}
		i++;
	}
	res[i] = NULL;
	return (res);
}
