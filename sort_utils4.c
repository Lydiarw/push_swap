/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-wong <si-wong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 12:35:34 by si-wong           #+#    #+#             */
/*   Updated: 2026/04/27 14:30:46 by si-wong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_rotate(t_ps *data, int a, int b)
{
	while (same_direction(a, b) == 1 && a > 0)
	{
		rr(data);
		a--;
		b--;
	}
	while (a > 0)
	{
		ra(data);
		a--;
	}
	while (b > 0)
	{
		rb(data);
		b--;
	}
}

void	handle_rev_rotate(t_ps *data, int a, int b)
{
	while (same_direction(a, b) == 1 && a < 0)
	{
		rrr(data);
		a++;
		b++;
	}
	while (a < 0)
	{
		rra(data);
		a++;
	}
	while (b < 0)
	{
		rrb(data);
		b++;
	}
}

void	move_to_top_from_a(t_ps *data, t_list *node)
{
	int		cost_a;
	int		cost_b;
	t_list	*target;

	cost_a = rotations_to_top(data->a, node);
	target = find_target_in_b(data->b, *(int *)node->content);
	cost_b = rotations_to_top(data->b, target);
	handle_rotate(data, cost_a, cost_b);
	handle_rev_rotate(data, cost_a, cost_b);
}

void	move_to_top_from_b(t_ps *data, t_list *node)
{
	int		cost_a;
	int		cost_b;
	t_list	*target;

	cost_b = rotations_to_top(data->b, node);
	target = find_target_in_a(data->a, *(int *)node->content);
	cost_a = rotations_to_top(data->a, target);
	handle_rotate(data, cost_a, cost_b);
	handle_rev_rotate(data, cost_a, cost_b);
}
