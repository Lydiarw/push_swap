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

void	move_to_top(t_ps *data, t_list *node)
{
	int	cost_a;
	int	cost_b;

	cost_a = rotations_to_top(data->a, node);
	cost_b = rotations_to_top(data->b, node);
	handle_rotate(data, cost_a, cost_b);
	handle_rev_rotate(data, cost_a, cost_b);
}

void	sort_stack(t_ps *data, int len)
{
	t_list	*node;

	if (len == 1)
		error_message(3);
	else if (len > 3)
	{
		pb(data);
		pb(data);
		while (ft_lstsize(data->a) > 3)
		{
			node = find_cheapest(data);
			move_to_top(data, node);
			pb(data);
		}
	}
	printf("%s\n", "DONE CALCULATING COSTS BITCHES!!!!!!");
	if (len <= 3)
		sort_three(data);
}
	// 	while (i < ft_max(cost_a, cost_b))
	// 	{
	// 		if (cost_a > 0 && same_direction(cost_a, cost_b) == 1
	// 			&& i < ft_min(cost_a, cost_b))
	// 			rr(data);
	// 		else if (cost_a > 0 && ABS(cost_a) > ABS(cost_b))
	// 			ra(data);
	// 		else if (cost_a > 0 && ABS(cost_b) > ABS(cost_a))
	// 			rb(data);
	// 		else if (cost_a < 0 && same_direction(cost_a, cost_b) == 1
	// 			&& i < ft_min(cost_a, cost_b))
	// 			rrr(data);
	// 		else if (cost_a < 0 && ABS(cost_a) > ABS(cost_b))
	// 			rra(data);
	// 		else if (cost_a < 0 && ABS(cost_b) > ABS(cost_a))
	// 			rrb(data);
	// 		i++;
	//     }
	//     while (cost_a != 0 && cost_b != 0)
	//     {
	//         if (cost_a > 0)
	//         {
	//             ra(data);
	//             cost_a--;
	//         }
	//         else if (cost_b > 0)
	//         {
	//             rb(data);
	//             cost_b--;
	//         }
	//         else if (cost_a < 0)
	//         {
	//             rra(data);
	//             cost_a++;
	//         }
	//         else if (cost_b < 0)
	//         {
	//             rrb(data);
	//             cost_b++;
	//         }
	//         else if (same_direction(cost_a, cost_b) == 1 && cost_a > 0)
	//         {
	//             rr(data);
	//             cost_a--;
	//             cost_b--;
	//             //how to make cost_a stop at 6,
	// and cost_b to continue 2 more.
		//         }
		// }
