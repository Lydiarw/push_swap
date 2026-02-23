/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-wong <si-wong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:02:50 by si-wong           #+#    #+#             */
/*   Updated: 2026/02/05 11:01:00 by si-wong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	isneg;
	int	ans;

	i = 0;
	isneg = 1;
	ans = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			isneg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ans *= 10;
		ans += str[i] - '0';
		i++;
	}
	return (isneg * ans);
}

/*int	main(void)
{
	char str[] = "  +123";
	char str1[] = "-567";
	char str2[] = "-+567";
	char str3[] = "--1";
	printf("%i\n", ft_atoi(str));
	printf("%i\n", ft_atoi(str1));
	printf("%i\n", ft_atoi(str2));
	printf("%i\n", ft_atoi(str3));
}*/
