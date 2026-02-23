/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-wong <si-wong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:27:47 by si-wong           #+#    #+#             */
/*   Updated: 2026/02/05 11:01:00 by si-wong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			((char *)dst)[i] = ((const char *)src)[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i > 0)
		{
			i--;
			((char *)dst)[i] = ((const char *)src)[i];
		}
	}
	return (dst);
}

/*int main()
{
	char src[] = "ABCDEFGH";
	char dst[8];
	char sResult[] = {67, 68, 67, 68, 69, 0, 45};

	ft_memmove(dst+1, src, 6);
	dst[7] = '\0';
	printf("Ans: %s\n", dst);
	// ft_memmove(sResult + 1, sResult, 2);
	// printf("Ans: %s\n", sResult);
}*/

/*If dst < src, it copies left to right.
If dst > src, it copies right to left*/