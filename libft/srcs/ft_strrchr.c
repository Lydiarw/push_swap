/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-wong <si-wong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:31:40 by si-wong           #+#    #+#             */
/*   Updated: 2026/02/05 11:01:00 by si-wong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*last;

	last = NULL;
	while (*str)
	{
		if (*str == (unsigned char)c)
			last = (char *)str;
		str++;
	}
	if (*str == '\0' && (unsigned char)c == '\0')
		return ((char *)str);
	return (last);
}

/*int main()
{
	char str[16] = "Yellow Bellow!";
	int c = 'o';

	printf("%s\n", ft_strrchr(str, c));
}*/