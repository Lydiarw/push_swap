#include "push_swap.h"

void	swap(t_list **list)
{
	t_list	*elem;
	t_list	*temp;

	if (!list || !*list)
		return ;
	elem = *list;
	if (!elem->next)
		return ;
	temp = elem->next;
	elem->next = elem->next->next;
	*list = elem;
	ft_lstadd_front(list, temp);
}

void	sa(t_ps *data)
{
	swap(&data->a);
	ft_lstadd_back(&data->res, ft_lstnew(ft_strdup(data->ops->sa)));
}

void	sb(t_ps *data)
{
	swap(&data->b);
	ft_lstadd_back(&data->res, ft_lstnew(ft_strdup(data->ops->sb)));
}

void	ss(t_ps *data)
{
	swap(&data->a);
	swap(&data->b);
	ft_lstadd_back(&data->res, ft_lstnew(ft_strdup(data->ops->ss)));
}

// int	main(void)
// {
// 	t_list *list1;
// 	t_list *list2;
// 	t_list *list3;
// 	int a[1];
// 	int b[1];
// 	int c[1];
// 	*a = 2;
// 	*b = 4;
// 	*c = 6;
// 	list1 = ft_lstnew(a);
// 	list2 = ft_lstnew(b);
// 	list3 = ft_lstnew(c);
// 	ft_lstadd_back(&list1, list2);
// 	ft_lstadd_back(&list1, list3);
// 	swap(&list1);
// 	printf("first: %i\n", *(int *)list1->content);
// 	printf("second: %i\n", *(int *)list1->next->content);
// 	printf("third: %i\n", *(int *)list1->next->next->content);
// }