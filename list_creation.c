#include "push_swap.h"

int	get_index(int *array, int index, int arr_len)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (++i < arr_len)
	{
		if (i == index)
			continue ;
		if (array[i] < array[index])
			count++;
	}
	return (count);
}

void	list_creation(t_list **begin_list, int arr_len, int *array)
{
	int *num;
	int i;

	i = -1;
	while (++i < arr_len)
	{
		num = malloc(sizeof(int));
		*num = get_index(array, i, arr_len);
		ft_lstadd_back(begin_list, ft_lstnew(num));
	}
}