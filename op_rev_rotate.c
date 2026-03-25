#include "push_swap.h"

void	rev_rotate(t_list **list)
{
	t_list	*elem;
	t_list	*last_node;

	if (!list || !*list)
		return ;
	elem = *list;
	while (elem->next)
	{
		last_node = elem;
		elem = elem->next;
	}
	last_node->next = NULL;
	ft_lstadd_front(list, elem);
}

void	rra(t_ps *data)
{
	rev_rotate(&data->a);
	ft_lstadd_back(&data->res, ft_lstnew(ft_strdup(data->ops->rra)));
}

void	rrb(t_ps *data)
{
	rev_rotate(&data->b);
	ft_lstadd_back(&data->res, ft_lstnew(ft_strdup(data->ops->rrb)));
}

void	rrr(t_ps *data)
{
	rev_rotate(&data->a);
	rev_rotate(&data->b);
	ft_lstadd_back(&data->res, ft_lstnew(ft_strdup(data->ops->rrr)));
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
// 	rev_rotate(&list1);
// 	while (list1)
// 	{
// 		printf("a%i: %i\n", i, *(int *)list1->content);
// 		i++;
// 		list1 = list1->next;
// 	}
// }