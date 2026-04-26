/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-wong <si-wong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 12:33:46 by si-wong           #+#    #+#             */
/*   Updated: 2026/04/01 12:33:49 by si-wong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_memory(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	error_message(int num)
{
	if (num == 1)
		ft_printf("%s\n", "ERROR: please input numbers only");
	else if (num == 2)
		ft_printf("%s\n", "ERROR: duplicate values");
	else if (num == 3)
		ft_printf("%s\n", "ERROR: please in put more than one number");
	exit(1);
}