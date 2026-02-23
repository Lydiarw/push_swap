/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-wong <si-wong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:24:07 by si-wong           #+#    #+#             */
/*   Updated: 2026/02/05 11:01:00 by si-wong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*void capitalize(void *any)
{
	char	*str;

	str = (char *)any;
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
}*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
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

	ft_lstiter(n1, capitalize);

	printf("After: %s\n", (char *)n1->content);
	printf("After: %s\n", (char *)n1->next->content);
	printf("After: %s\n", (char *)n1->next->next->content);
}*/