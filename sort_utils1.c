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

int	calculate_cost(t_ps *data, t_list *node)
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

t_list	*find_cheapest(t_ps *data)
{
	t_list *curr;
	t_list *best;
	int cost;
	int best_cost;

	curr = data->a;
	best_cost = INT_MAX;
	while (curr)
	{
		cost = calculate_cost(data, curr);
		if (cost < best_cost)
		{
			best_cost = cost;
			best = curr;
		}
		curr = curr->next;
	}
	return (best);
}