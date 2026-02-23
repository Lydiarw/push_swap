/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-wong <si-wong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:30:25 by si-wong           #+#    #+#             */
/*   Updated: 2026/02/05 11:01:00 by si-wong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*res;

	res = (char *)str;
	while (*res)
	{
		if (*res == (unsigned char)c)
			return (&*res);
		res++;
	}
	if (*res == '\0' && (unsigned char)c == '\0')
		return (res);
	return (NULL);
}

/*int main()
{
	char str[16] = "Yellow Bellow!";
	int c = 'o';
	int d = 'a';

	printf("%s\n", ft_strchr(str, c));
	printf("%s\n", ft_strchr(str, d));
}*/