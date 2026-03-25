#include "push_swap.h"

void	push(t_list **list_a, t_list **list_b)
{
	t_list	*temp;

	if (!list_a || !*list_a || !list_b || !*list_b)
		return ;
	temp = *list_b;
	*list_b = temp->next;
	ft_lstadd_front(list_a, temp);
}

void	pa(t_ps *data)
{
	push(&data->a, &data->b);
	ft_lstadd_back(&data->res, ft_lstnew(ft_strdup(data->ops->pa)));
}

void	pb(t_ps *data)
{
	push(&data->b, &data->a);
	ft_lstadd_back(&data->res, ft_lstnew(ft_strdup(data->ops->pb)));
}

// int	main(void)
// {
// 	int i = 1;
// 	int k = 1;
// 	t_list *list1;
// 	t_list *list2;
// 	t_list *list3;
// 	t_list *list4;
// 	t_list *list5;
// 	t_list *list6;
// 	int a[1];
// 	int b[1];
// 	int c[1];
// 	int d[1];
// 	int e[1];
// 	int f[1];
// 	*a = 1;
// 	*b = 2;
// 	*c = 3;
// 	*d = 4;
// 	*e = 5;
// 	*f = 6;
// 	list1 = ft_lstnew(a);
// 	list2 = ft_lstnew(b);
// 	list3 = ft_lstnew(c);
// 	list4 = ft_lstnew(d);
// 	list5 = ft_lstnew(e);
// 	list6 = ft_lstnew(f);
// 	ft_lstadd_back(&list1, list2);
// 	ft_lstadd_back(&list1, list3);
// 	ft_lstadd_back(&list4, list5);
// 	ft_lstadd_back(&list4, list6);
// 	push(&list1, &list4);
// 	t_list *elem_a = list1;
// 	t_list *elem_b = list4;
// 	while (elem_a)
// 	{
// 		printf("a%i: %i\n", i, *(int *)elem_a->content);
// 		i++;
// 		elem_a = elem_a->next;
// 	}
// 	while (elem_b)
// 	{
// 		printf("b%i: %i\n", k, *(int *)elem_b->content);
// 		k++;
// 		elem_b = elem_b->next;
// 	}
// 	push(&list4, &list1);
//     i = 1;
//     k = 1;
//     elem_a = list1;
//     elem_b = list4;
//     printf("~~~~~~\n");
// 	while (elem_a)
// 	{
// 		printf("A%i: %i\n", i, *(int *)elem_a->content);
// 		i++;
// 		elem_a = elem_a->next;
// 	}
// 	while (elem_b)
// 	{
// 		printf("B%i: %i\n", k, *(int *)elem_b->content);
// 		k++;
// 		elem_b = elem_b->next;
// 	}
// }