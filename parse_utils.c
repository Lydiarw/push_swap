/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-wong <si-wong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 12:34:58 by si-wong           #+#    #+#             */
/*   Updated: 2026/04/27 01:57:11 by si-wong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int is_valid_number(char *str)
{
	int	i;

	if (!str || !*str)
		return (-1);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (-1);
	while(str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}

void	validate_input(char **input)
{
	int	i;

	if (!input || !input[0])
		error_message();
	i = 0;
	while (input[i])
	{
		if (is_valid_number(input[i]) == -1)
			error_message();
		i++;
	}
}

int	safe_atoi(const char *str, int *out)
{
	int	i;
	int	sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if (sign == 1 && res > INT_MAX)
			return (-1);
		if (sign == -1 && -res < INT_MIN)
			return (-1);
		i++;
	}
	*out = (int)(res * sign);
	return (0);
}

/* checks for duplicates in int array */
/* uses arr_len as a stopper (no NULL terminator in int arrays) */
int	check_duplicates(int *array, int arr_len)
{
	int i;
	int j;

	i = -1;
	while (++i < arr_len)
	{
		j = i;
		while (++j < arr_len)
		{
			if (array[i] == array[j])
				return (-1);
		}
	}
	return (0);
}