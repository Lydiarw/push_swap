#include "push_swap.h"

void	swap(t_list **list)
{
	t_list	*elem;
	t_list	*temp;

	if (!list || !*list)
		return ;
	elem = *list;
	if (elem->next)
		return ;
	temp = elem->content;
	elem->content = elem->next->content;
	elem->next->content = temp;
}

void	push(t_list **list_a, t_list **list_b)
{
	t_list	*elem_a;
	t_list	*elem_b;

	if (!list_a || !*list_a || !list_b || !*list_b)
		return ;
	elem_a = *list_a;
	elem_b = *list_b;
	*list_a = elem_a->next;
	*list_b = elem_b->next;
	ft_lstadd_front(list_a, elem_b);
	ft_lstadd_front(list_b, elem_a);
}

void	rotate(t_list **list)
{
	t_list	*elem;

	if (!list || !*list)
		return ;
	elem = *list;
	*list = elem->next;
	ft_lstadd_back(list, elem);
}

void	rev_rotate(t_list **list)
{
	t_list *elem;

	if (!list || !*list)
		return ;
	elem = *list;
	while (elem->next)
		elem = elem->next;
	ft_lstadd_front(list, elem);
}

/*int	main(void)
{
	// FOR SWAP
	// t_list	*list1;
	// t_list	*list2;
	// t_list	*list3;
	// int		a[1];
	// int		b[1];
	// int		c[1];
	// *a = 2;
	// *b = 4;
	// *c = 6;
	// list1 = ft_lstnew(a);
	// list2 = ft_lstnew(b);
	// list3 = ft_lstnew(c);
	// ft_lstadd_back(&list1, list2);
	// ft_lstadd_back(&list1, list3);
	// swap(&list1);
	// printf("first: %i\n", *(int *)list1->content);
	// printf("second: %i\n", *(int *)list1->next->content);
	// printf("third: %i\n", *(int *)list1->next->next->content);

	// FOR PUSH
	// t_list	*list1;
	// t_list	*list2;
	// t_list	*list3;
	// t_list	*list4;
	// t_list	*list5;
	// t_list	*list6;
	// int		a[1];
	// int		b[1];
	// int		c[1];
	// int		d[1];
	// int		e[1];
	// int		f[1];
	// *a = 1;
	// *b = 2;
	// *c = 3;
	// *d = 4;
	// *e = 5;
	// *f = 6;
	// list1 = ft_lstnew(a);
	// list2 = ft_lstnew(b);
	// list3 = ft_lstnew(c);
	// list4 = ft_lstnew(d);
	// list5 = ft_lstnew(e);
	// list6 = ft_lstnew(f);
	// ft_lstadd_back(&list1, list2);
	// ft_lstadd_back(&list1, list3);
	// ft_lstadd_back(&list4, list5);
	// ft_lstadd_back(&list4, list6);
	// push(&list1, &list4);
	// printf("a1: %i\n", *(int *)list1->content);
	// printf("a2: %i\n", *(int *)list1->next->content);
	// printf("a3: %i\n", *(int *)list1->next->next->content);
	// printf("b1: %i\n", *(int *)list4->content);
	// printf("b2: %i\n", *(int *)list4->next->content);
	// printf("b3: %i\n", *(int *)list4->next->next->content);

	// FOR ROTATE
	// t_list	*list1;
	// t_list	*list2;
	// t_list	*list3;
	// t_list	*list4;
	// int		a[1];
	// int		b[1];
	// int		c[1];
	// int		d[1];
	// *a = 1;
	// *b = 2;
	// *c = 3;
	// *d = 4;
	// list1 = ft_lstnew(a);
	// list2 = ft_lstnew(b);
	// list3 = ft_lstnew(c);
	// list4 = ft_lstnew(d);
	// ft_lstadd_back(&list1, list2);
	// ft_lstadd_back(&list1, list3);
	// ft_lstadd_back(&list1, list4);
	// rotate(&list1);
	// printf("a1: %i\n", *(int *)list1->content);
	// printf("a2: %i\n", *(int *)list1->next->content);
	// printf("a3: %i\n", *(int *)list1->next->next->content);
	// printf("a4: %i\n", *(int *)list1->next->next->next->content);

	// FOR REVERSE ROTATE
	// t_list	*list1;
	// t_list	*list2;
	// t_list	*list3;
	// t_list	*list4;
	// int		a[1];
	// int		b[1];
	// int		c[1];
	// int		d[1];

	// *a = 1;
	// *b = 2;
	// *c = 3;
	// *d = 4;
	// list1 = ft_lstnew(a);
	// list2 = ft_lstnew(b);
	// list3 = ft_lstnew(c);
	// list4 = ft_lstnew(d);
	// ft_lstadd_back(&list1, list2);
	// ft_lstadd_back(&list1, list3);
	// ft_lstadd_back(&list1, list4);
	// rev_rotate(&list1);
	// printf("a1: %i\n", *(int *)list1->content);
	// printf("a2: %i\n", *(int *)list1->next->content);
	// printf("a3: %i\n", *(int *)list1->next->next->content);
	// printf("a4: %i\n", *(int *)list1->next->next->next->content);
}*/