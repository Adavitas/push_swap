#ifndef  UTILS_H
#define  UTILS_H

#include <stdlib.h>
#include "ft_printf.h"
#include "push_swap.h"

typedef struct s_list t_list;

void    ft_check_err(char **argv);

t_list  *ft_new_node(int nbr);
t_list  *ft_last_node(t_list *first);
void    ft_node_to_stack(t_list **stack, t_list *node);
int ft_stack_len(t_list *first);

void    ft_err(char *err);
void    ft_free_string(char **arr);
void    ft_free_stack(t_list **stack);

char	**ft_split(char *s, char c);
int	ft_atoi(char *nptr);
int	ft_isdigit(int c);
int	ft_strcmp(char *s1, char *s2);

#endif  
