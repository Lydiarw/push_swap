#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/ft_printf.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

void	swap(t_list **list);
void	push(t_list **list_a, t_list **list_b);
void	rotate(t_list **list);
void	rev_rotate(t_list **list);
void	error_message(int num);
int		number_and_sep_only(char *str, char sep);
int		check_duplicates(t_list **begin_list);
void	free_memory(char **array);
void	args_to_list(t_list **begin_list, char **array);
void list_creation(int argc, char **argv, t_list **begin_list);

#endif