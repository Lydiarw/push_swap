/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-wong <si-wong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:27:09 by si-wong           #+#    #+#             */
/*   Updated: 2026/02/05 11:01:00 by si-wong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	if (!lst)
		return (0);
	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

/*int main()
{
	t_list  *list1;
	t_list  *list2;
	t_list  *list3;
	int a[1];

	list1 = ft_lstnew(&a);
	list2 = ft_lstnew(&a);
	list3 = ft_lstnew(&a);
	ft_lstadd_front(&list1, list2);
	ft_lstadd_front(&list1, list3);

	int ans = ft_lstsize(list1);
	printf("%i", ans);
}*/