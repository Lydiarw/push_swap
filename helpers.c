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

int	ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

/*
	checks for duplicates in int array
	uses arr_len as a stopper (no NULL terminator in int arrays)
*/
int	check_duplicates(int *array, int arr_len)
{
	int	i;
	int	j;

	i = -1;
	while (++i < arr_len)
	{
		j = i;
		while (++j < arr_len)
		{
			if (array[i] == array[j])
				return (-1);
		}
	}
	return (0);
}

void	error_message(int num)
{
	if (num == 1)
		ft_printf("%s\n", "ERROR: please input numbers only");
	if (num == 2)
		ft_printf("%s\n", "ERROR: duplicate values");
	exit(1);
}