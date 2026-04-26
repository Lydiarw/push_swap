/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-wong <si-wong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 12:35:48 by si-wong           #+#    #+#             */
/*   Updated: 2026/04/01 12:35:49 by si-wong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_ps *data)
{
	t_list	*current;
	t_list	*max_node;

	current = data->a;
	max_node = find_max(data->a);
	if (*(int *)current->content == *(int *)max_node->content)
		ra(data);
	else if (*(int *)current->next->content == *(int *)max_node->content)
		rra(data);
	current = data->a;
	if (*(int *)current->content > *(int *)current->next->content)
		sa(data);
}

void	final_rotate(t_ps *data)
{
	t_list	*min_node;
	int		cost_a;

	min_node = find_min(data->a);
	cost_a = rotations_to_top(data->a, min_node);
	handle_rotate(data, cost_a, 0);
	handle_rev_rotate(data, cost_a, 0);
}

void	sort_big(t_ps *data)
{
	t_list	*node;

	pb(data);
	pb(data);
	while (ft_lstsize(data->a) > 3)
	{
		node = find_cheapest_in_a(data);
		move_to_top_from_a(data, node);
		pb(data);
	}
	sort_three(data);
	while (ft_lstsize(data->b) > 0)
	{
		node = find_cheapest_in_b(data);
		move_to_top_from_b(data, node);
		pa(data);
	}
	final_rotate(data);
}

void	sort_stack(t_ps *data, int len)
{
	if (len == 1)
		error_message(3);
	else if (len <= 3)
		sort_three(data);
	else if (len > 3)
		sort_big(data);
}