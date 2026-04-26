/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-wong <si-wong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 12:35:21 by si-wong           #+#    #+#             */
/*   Updated: 2026/04/01 12:35:21 by si-wong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_max(t_list *begin_list)
{
	t_list	*curr;
	t_list	*max;
	int		biggest;

	curr = begin_list;
	max = NULL;
	biggest = INT_MIN;
	while (curr)
	{
		if (*(int *)curr->content > biggest)
		{
			biggest = *(int *)curr->content;
			max = curr;
		}
		curr = curr->next;
	}
	return (max);
}

t_list	*find_min(t_list *begin_list)
{
	t_list	*curr;
	t_list	*min;
	int		smallest;

	curr = begin_list;
	smallest = INT_MAX;
	while (curr)
	{
		if (*(int *)curr->content < smallest)
		{
			smallest = *(int *)curr->content;
			min = curr;
		}
		curr = curr->next;
	}
	return (min);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	same_direction(int a, int b)
{
	if ((a > 0 && b > 0) || (a < 0 && b < 0))
		return (1);
	return (0);
}