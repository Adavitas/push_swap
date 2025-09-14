#include "checker.h"

size_t	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	if ((char)c == '\0')
		return (s);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	if (dst == NULL || src == NULL || !size)
		return (len);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

char	*ft_strdup(char *s)
{
	char	*str;
	int		buffer_size;

	if (!s)
		return (NULL);
	buffer_size = ft_strlen(s) + 1;
	str = malloc(buffer_size);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s, buffer_size);
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (s1);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcpy(str + s1_len, s2, s2_len + 1);
	free(s1);
	return (str);
}