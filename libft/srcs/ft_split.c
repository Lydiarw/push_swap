/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-wong <si-wong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:30:20 by si-wong           #+#    #+#             */
/*   Updated: 2026/02/05 11:01:00 by si-wong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_count_array(char const *str, char c)
{
	int	flag;
	int	count;

	flag = 0;
	count = 0;
	while (*str)
	{
		if (*str != c && flag == 0)
		{
			flag = 1;
			count++;
		}
		if (*str == c)
			flag = 0;
		str++;
	}
	return (count);
}

size_t	ft_skip_char(char const *s, char c, size_t i)
{
	while (s[i] == c && s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_count_letter(char const *s, char c, size_t i, size_t j)
{
	while (s[i + j] != c && s[i + j] != '\0')
		j++;
	return (j);
}

char	*ft_letter_dup(char const *s, size_t start, size_t end)
{
	char	*res;
	size_t	i;

	i = 0;
	res = (char *)malloc((end - start + 1) * sizeof(char));
	if (!res)
		return (res);
	while (start < end)
	{
		res[i] = s[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s)
		return (NULL);
	res = (char **)malloc((ft_count_array(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		i = ft_skip_char(s, c, i);
		if (s[i] == '\0')
			break ;
		j = ft_count_letter(s, c, i, 0);
		res[k] = ft_letter_dup(s, i, (i + j));
		k++;
		i += j;
	}
	res[k] = NULL;
	return (res);
}

/*int main()
{
	// char s[40] = "Hello,I love Fan Xu,Hank and Mengo!";
	// char c = ',';
	// char s[] = "\0aa\0bbb";
	// char c = '\0';
	size_t i;
	char **res = ft_split(s, c);

	i = 0;
	while(res[i] != NULL)
	{
		printf("%s\n", res[i]);
		i++;
	}
}*/