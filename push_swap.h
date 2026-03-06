#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/ft_printf.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_ops
{
	char	*sa;
	char	*sb;
	char	*ss;
	char	*pa;
	char	*pb;
	char	*ra;
	char	*rb;
	char	*rr;
	char	*rra;
	char	*rrb;
	char	*rrr;
}			t_ops;

typedef struct s_ps
{
	t_list	*a;
	t_list	*b;
	t_list	*res;
	t_ops	*ops;
}			t_ps;

void		assign_index(t_list **list);

/* Initialization */
t_ops		*initialize_ops(void);
t_ps		*initialize_ps();

/* Parsing */
int			is_number_and_seperator(char *str, char sep);
void		validate_number_and_seperator(int argc, char **argv);
char		**get_array(int argc, char **argv);
int			*to_int_array(char **array, int *length);
int			parse_args(int argc, char **argv, int **res);

/* helper functions */
void		error_message(int num);
void		free_memory(char **array);
int			ft_arrlen(char **arr);
int			check_duplicates(int *array, int arr_len);

/* List Creation */
int			get_index(int *array, int index, int arr_len);
void		list_creation(t_list **begin_list, int arr_len, int *array);
// int			is_number_and_seperator(char *str, char sep);
// int			check_duplicates(t_list **begin_list);
// void		args_to_list(t_list **begin_list, char **array);
// void		list_creation(int argc, char **argv, t_list **begin_list);

/* Operations */
void		swap(t_list **list);
void		sa(t_ps *data);
void		sb(t_ps *data);
void		ss(t_ps *data);
void		push(t_list **list_a, t_list **list_b);
void		pa(t_ps *data);
void		pb(t_ps *data);
void		rotate(t_list **list);
void		ra(t_ps *data);
void		rb(t_ps *data);
void		rr(t_ps *data);
void		rev_rotate(t_list **list);
void		rra(t_ps *data);
void		rrb(t_ps *data);
void		rrr(t_ps *data);

#endif