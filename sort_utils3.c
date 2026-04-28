/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-wong <si-wong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 12:35:31 by si-wong           #+#    #+#             */
/*   Updated: 2026/04/27 14:33:42 by si-wong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_cheapest_in_a(t_ps *data)
{
	t_list	*curr;
	t_list	*best;
	int		cost;
	int		best_cost;

	curr = data->a;
	best_cost = INT_MAX;
	while (curr)
	{
		cost = calculate_cost_from_a(data, curr);
		if (cost < best_cost)
		{
			best_cost = cost;
			best = curr;
		}
		curr = curr->next;
	}
	return (best);
}

t_list	*find_cheapest_in_b(t_ps *data)
{
	t_list	*curr;
	t_list	*best;
	int		cost;
	int		best_cost;

	curr = data->b;
	best_cost = INT_MAX;
	while (curr)
	{
		cost = calculate_cost_from_b(data, curr);
		if (cost < best_cost)
		{
			best_cost = cost;
			best = curr;
		}
		curr = curr->next;
	}
	return (best);
}
