/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-wong <si-wong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:27:31 by si-wong           #+#    #+#             */
/*   Updated: 2026/02/05 11:01:00 by si-wong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	// char s1[] = "aChewy";
	// char s2[] = "zCheby";

	// printf("Ans: %d\n", ft_memcmp(s1, s2, 0));
	// printf("Ans: %d\n", ft_memcmp(s1, s2, 3));

	char s[] = {-128, 0, 127, 0};
	char sCpy[] = {-128, 0, 127, 0};
	char s2[] = {0, 0, 127, 0};
	char s3[] = {0, 0, 42, 0};
	printf("%d\n", ft_memcmp(s, sCpy, 4)); //0
	printf("%d\n", ft_memcmp(s, s2, 0)); // 0
	printf("%d\n", ft_memcmp(s, s2, 1)); // 128
	printf("%d\n", ft_memcmp(s2, s, 1)); // - 128
	printf("%d\n", ft_memcmp(s2, s3, 4)); // 85
}*/