/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-wong <si-wong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 12:33:56 by si-wong           #+#    #+#             */
/*   Updated: 2026/04/27 14:13:22 by si-wong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* counting the no. of numbers smaller than the MAIN NUMBER to get its index */
int	get_index(int *array, int index, int arr_len)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (++i < arr_len)
	{
		if (i == index)
			continue ;
		if (array[i] < array[index])
			count++;
	}
	return (count);
}

void	list_creation(t_list **begin_list, int arr_len, int *array)
{
	int	*num;
	int	i;

	i = -1;
	while (++i < arr_len)
	{
		num = malloc(sizeof(int));
		*num = get_index(array, i, arr_len);
		ft_lstadd_back(begin_list, ft_lstnew(num));
	}
}
