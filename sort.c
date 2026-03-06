#include "push_swap.h"

int	find_highest(t_list **begin_list)
{
	t_list	*current;
	int		highest_num;

	current = *begin_list;
	highest_num = INT_MIN;
	while (current)
	{
		if (*(int *)current->content > highest_num)
			highest_num = *(int *)current->content;
		current = current->next;
	}
	return (highest_num);
}

void	sort_three(t_ps *data)
{
	t_list *current;
	int highest_num;

	current = data->a;
	highest_num = find_highest(data->a);
	if (*(int *)current->content == highest_num)
		ra(data);
	else if (*(int *)current->next->content == highest_num)
		rra(data);
	if (*(int *)current->content > *(int *)current->next->content)
		sa(data);
}