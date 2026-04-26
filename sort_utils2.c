/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-wong <si-wong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 12:35:25 by si-wong           #+#    #+#             */
/*   Updated: 2026/04/01 12:35:27 by si-wong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* find index */
/* that NODE which u use to compare to the rest of the list */
int	rotations_to_top(t_list *begin_list, t_list *node)
{
	t_list	*curr;
	int		size;
	int		index;

	curr = begin_list;
	size = ft_lstsize(curr);
	index = 0;
	while (curr)
	{
		if (curr == node)
			break ;
		index++;
		curr = curr->next;
	}
	if (index <= size / 2)
		return (index); /* pos: ra/rb */
	else
		return (index - size); /* neg: rra/rrb */
}

t_list	*find_target_in_b(t_list *begin_list, int value)
{
	t_list	*curr;
	t_list	*best;

	curr = begin_list;
	best = NULL;
	while (curr)
	{
		if (*(int *)curr->content < value)
		{
			if (!best || *(int *)curr->content > *(int *)best->content)
				best = curr;
		}
		curr = curr->next;
	}
	if (!best)
		best = find_max(begin_list);
	return (best);
}

t_list	*find_target_in_a(t_list *begin_list, int value)
{
	t_list	*curr;
	t_list	*best;

	curr = begin_list;
	best = NULL;
	while (curr)
	{
		if (*(int *)curr->content > value)
		{
			if (!best || *(int *)curr->content < *(int *)best->content)
				best = curr;
		}
		curr = curr->next;
	}
	if (!best)
		best = find_min(begin_list);
	return (best);
}

int	calculate_cost_from_a(t_ps *data, t_list *node)
{
	int		cost_a;
	int		cost_b;
	t_list	*target;

	cost_a = rotations_to_top(data->a, node);
	target = find_target_in_b(data->b, *(int *)node->content);
	cost_b = rotations_to_top(data->b, target);
	if (same_direction(cost_a, cost_b) == 1)
		return (ft_max(ABS(cost_a), ABS(cost_b)) + 1);
	else
		return (ABS(cost_a) + ABS(cost_b) + 1);
}

int	calculate_cost_from_b(t_ps *data, t_list *node)
{
	int cost_a;
	int cost_b;
	t_list *target;

	cost_b = rotations_to_top(data->b, node);
	target = find_target_in_a(data->a, *(int *)node->content);
	cost_a = rotations_to_top(data->a, target);
	if (same_direction(cost_a, cost_b) == 1)
		return (ft_max(ABS(cost_a), ABS(cost_b)) + 1);
	else
		return (ABS(cost_a) + ABS(cost_b) + 1);
}