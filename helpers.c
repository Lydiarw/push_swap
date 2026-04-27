/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-wong <si-wong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 12:33:46 by si-wong           #+#    #+#             */
/*   Updated: 2026/04/27 02:09:12 by si-wong          ###   ########.fr       */
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

void	error_message(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	print_res(t_ps *data)
{
	t_list	*current;

	current = data->res;
	while (current)
	{
		ft_printf("%s\n", (char *)current->content);
		current = current->next;
	}
}

void	free_data(t_ps *data)
{
	if (!data)
		return ;
	ft_lstclear(&data->a, free);
	ft_lstclear(&data->b, free);
	ft_lstclear(&data->res, free);
	free(data->ops);
	free(data);
}