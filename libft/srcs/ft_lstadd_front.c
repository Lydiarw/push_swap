/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-wong <si-wong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:23:50 by si-wong           #+#    #+#             */
/*   Updated: 2026/02/05 11:01:00 by si-wong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*int main()
{
	int a[1];
	int b[1];
	*a = 3;
	*b = 5;

	t_list *lst;
	t_list *new;
	lst = ft_lstnew(&a);
	new = ft_lstnew(&b);

	lst->content = a;
	new->content = b;

	ft_lstadd_front(&lst, new);
	printf("first: %i\n", *(int *)lst->content);
	printf("second: %i\n", *(int *)lst->next->content);
}*/