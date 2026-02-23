/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-wong <si-wong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:27:39 by si-wong           #+#    #+#             */
/*   Updated: 2026/02/05 11:01:00 by si-wong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*destin;
	const char	*source;
	size_t		i;

	if (!dest && !src)
		return (NULL);
	source = src;
	destin = (char *)dest;
	i = 0;
	while (i < n)
	{
		destin[i] = source[i];
		i++;
	}
	return ((void *)destin);
}

/*int main()
{
	// char *dest = (char *)malloc(8 * sizeof(char));
	// char src[] = "meowwif";

	printf("%s\n", (char *)ft_memcpy(NULL, NULL, 6));
}*/