/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-wong <si-wong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 12:35:10 by si-wong           #+#    #+#             */
/*   Updated: 2026/04/27 02:12:27 by si-wong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ops	*initialize_ops(void)
{
	t_ops	*ops;

	ops = (t_ops *)malloc(sizeof(t_ops));
	if (!ops)
		return (NULL);
	ops->sa = "sa";
	ops->sb = "sb";
	ops->ss = "ss";
	ops->pa = "pa";
	ops->pb = "pb";
	ops->ra = "ra";
	ops->rb = "rb";
	ops->rr = "rr";
	ops->rra = "rra";
	ops->rrb = "rrb";
	ops->rrr = "rrr";
	return (ops);
}

t_ps	*initialize_ps(void)
{
	t_ps	*data;

	data = (t_ps *)malloc(sizeof(t_ps));
	data->a = NULL;
	data->b = NULL;
	data->res = NULL;
	data->ops = initialize_ops();
	return (data);
}

void	print_list(t_list *list)
{
	t_list	*current;

	current = list;
	printf("===========START===========\n");
	while (current)
	{
		printf("list:   %d\n", *(int *)current->content);
		current = current->next;
	}
	printf("===========END===========\n");
}

int	main(int argc, char **argv)
{
	t_ps *data;
	int *res;
	int res_len;

	if (!argc || !argv || argc < 2)
		return (1);
	data = initialize_ps();
	res = NULL;
	res_len = parse_args(argc, argv, &res);
	if (res_len == 0)
		exit(0);
	list_creation(&data->a, res_len, res);
	sort_stack(data, res_len);
	while (data->res)
	{
		ft_printf("%s\n", *(char **)data->res);
		data->res = data->res->next;
	}
	free_data(data);
}