/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-wong <si-wong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:31:35 by si-wong           #+#    #+#             */
/*   Updated: 2026/02/05 11:01:00 by si-wong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	if (!haystack && !len)
		return (NULL);
	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		k = 0;
		while (haystack[k + i] == needle[k] && (k + i < len))
		{
			if (needle[k + 1] == '\0')
				return ((char *)haystack + i);
			k++;
		}
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char haystack[34] = "aaabcabcd";

	printf("Answer: %s\n", ft_strnstr(haystack, "aa", 0)); //null
	printf("Empty needle: %s\n", ft_strnstr(haystack, "", 4)); //haystack
	printf("nowhere: %s\n", ft_strnstr(haystack, "e", 4)); //NULL
	printf("3:  %s\n", ft_strnstr(haystack, "a", -1)); //aaabcabcd
	printf("4:  %s\n", ft_strnstr(haystack, "c", -1)); //cabcd
	printf("10:  %s\n", ft_strnstr(haystack, "abcd", 9)); // abcd
	printf("11:  %s\n", ft_strnstr(haystack, "cd", 8)); //NULL

	size_t max = ft_strlen("A") + 1;
	char *res = ft_strnstr("A", "A", max);
	printf("new:  %s\n", res); //3627
}*/