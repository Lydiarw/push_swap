#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/ft_printf.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

# define ABS(value) ((value) < 0 ? -(value) : (value))

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
t_ps		*initialize_ps(void);

/* Helper functions */
void		free_memory(char **array);
void		error_message(int num);

/* Parsing */
int			ft_arrlen(char **arr);
int			is_number_and_seperator(char *str, char sep);
void		validate_number_and_seperator(int argc, char **argv);
int			check_duplicates(int *array, int arr_len);
char		**get_array(int argc, char **argv);
int			*to_int_array(char **array, int *length);
int			parse_args(int argc, char **argv, int **res);

/* List Creation */
int			get_index(int *array, int index, int arr_len);
void		list_creation(t_list **begin_list, int arr_len, int *array);

/* Sorting */
t_list		*find_max(t_list *begin_list);
t_list		*find_target_in_b(t_list *begin_list, int value);
int			rotations_to_top(t_list *begin_list, t_list *node);
int			calculate_cost(t_ps *data, t_list *node);
t_list		*find_cheapest(t_ps *data);
int			same_direction(int a, int b);
int			ft_max(int a, int b);
void		sort_three(t_ps *data);
void		handle_rotate(t_ps *data, int a, int b);
void		handle_rev_rotate(t_ps *data, int a, int b);
void		move_to_top(t_ps *data, t_list *node);
void		sort_stack(t_ps *data, int len);

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