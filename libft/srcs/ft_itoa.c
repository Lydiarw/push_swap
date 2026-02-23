/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-wong <si-wong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:23:28 by si-wong           #+#    #+#             */
/*   Updated: 2026/02/05 11:01:00 by si-wong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_numlen(int n)
{
	int		len;
	long	l;

	len = 0;
	l = (long)n;
	if (l == 0)
		return (1);
	if (l < 0)
	{
		l *= -1;
		len++;
	}
	while (l > 0)
	{
		l /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*res;
	long	l;

	l = (long)n;
	i = ft_numlen(n);
	res = (char *)malloc((i + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (l < 0)
	{
		res[0] = '-';
		l *= -1;
	}
	res[i--] = '\0';
	if (l == 0)
		res[i] = '0';
	while (l > 0)
	{
		res[i--] = (l % 10) + '0';
		l /= 10;
	}
	return (res);
}

/*int	main(void)
{
	printf("%s\n", ft_itoa(-158));
	printf("%s\n", ft_itoa(24));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(INT_MIN));
}*/