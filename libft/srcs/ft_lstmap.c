/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-wong <si-wong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:24:44 by si-wong           #+#    #+#             */
/*   Updated: 2026/02/05 11:01:00 by si-wong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*void	*capitalize(void *any)
{
	char	*str;
	char	*original;

	str = (char *)any;
	original = str;
	while (*str)
	{
		*str = ft_toupper(*str);
		str++;
	}
	return ((void *)original);
}

void	delete(void *any)
{
	free(any);
}*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_elem;
	void	*new_content;

	new_list = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		new_content = f(lst->content);
		new_elem = ft_lstnew(new_content);
		if (!new_elem)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_elem);
		lst = lst->next;
	}
	return (new_list);
}

/*int main()
{
	char str1[6] = "hello";
	char str2[6] = "fanxu";
	char str3[5] = "hank";
	t_list *n1 = ft_lstnew(str1);
	t_list *n2 = ft_lstnew(str2);
	t_list *n3 = ft_lstnew(str3);

	ft_lstadd_back(&n1, n2);
	ft_lstadd_back(&n1, n3);

	printf("Before: %s\n", (char *)n1->content);
	printf("Before: %s\n", (char *)n1->next->content);
	printf("Before: %s\n", (char *)n1->next->next->content);

	ft_lstmap(n1, capitalize, delete);

	printf("After: %s\n", (char *)n1->content);
	printf("After: %s\n", (char *)n1->next->content);
	printf("After: %s\n", (char *)n1->next->next->content);
}*/