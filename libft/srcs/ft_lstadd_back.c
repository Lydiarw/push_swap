/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-wong <si-wong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:23:44 by si-wong           #+#    #+#             */
/*   Updated: 2026/02/05 11:01:00 by si-wong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

/*int main()
{
	t_list *list1;
	t_list *list2;
	t_list *list3;

	int a[1];
	int b[1];
	int c[1];
	*a = 3;
	*b = 5;
	*c = 7;

	list1 = ft_lstnew(&a);
	list2 = ft_lstnew(&b);
	list3 = ft_lstnew(&c);
	ft_lstadd_back(&list1, list2);
	ft_lstadd_back(&list1, list3);
	printf("first: %i\n", *(int *)list1->content);
	printf("second: %i\n", *(int *)list1->next->content);
	printf("third: %i\n", *(int *)list1->next->next->content);
}*/