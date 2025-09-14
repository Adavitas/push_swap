#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h" 
# include "ft_printf.h"
# include "utils.h" 

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int     checker(int argc, char **argv);
int     ft_operations_check(char *line, t_list **a, t_list **b);
char	*get_next_line(int fd);

char	*ft_strchr(char *str, int c);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
size_t	ft_strlen(char *str);

#endif
