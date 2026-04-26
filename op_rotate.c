/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-wong <si-wong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 12:34:49 by si-wong           #+#    #+#             */
/*   Updated: 2026/04/01 12:34:50 by si-wong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **list)
{
	t_list	*temp;

	if (!list || !*list)
		return ;
	temp = *list;
	*list = temp->next;
	temp->next = NULL;
	ft_lstadd_back(list, temp);
}

void	ra(t_ps *data)
{
	rotate(&data->a);
	ft_lstadd_back(&data->res, ft_lstnew(ft_strdup(data->ops->ra)));
}

void	rb(t_ps *data)
{
	rotate(&data->b);
	ft_lstadd_back(&data->res, ft_lstnew(ft_strdup(data->ops->rb)));
}

void	rr(t_ps *data)
{
	rotate(&data->a);
	rotate(&data->b);
	ft_lstadd_back(&data->res, ft_lstnew(ft_strdup(data->ops->rr)));
}

// int	main(void)
// {
// 	int i = 1;
// 	t_list *list1;
// 	t_list *list2;
// 	t_list *list3;
// 	t_list *list4;
// 	int a[1];
// 	int b[1];
// 	int c[1];
// 	int d[1];
// 	*a = 1;
// 	*b = 2;
// 	*c = 3;
// 	*d = 4;
// 	list1 = ft_lstnew(a);
// 	list2 = ft_lstnew(b);
// 	list3 = ft_lstnew(c);
// 	list4 = ft_lstnew(d);
// 	ft_lstadd_back(&list1, list2);
// 	ft_lstadd_back(&list1, list3);
// 	ft_lstadd_back(&list1, list4);
// 	rotate(&list1);
// 	while (list1)
// 	{
// 		printf("a%i: %i\n", i, *(int *)list1->content);
// 		i++;
// 		list1 = list1->next;
// 	}
// }