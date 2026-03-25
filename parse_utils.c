#include "push_swap.h"

int	ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

/* checks if str has unwanted chars */
int	is_number_and_seperator(char *str, char sep)
{
	while (*str)
	{
		if (sep == ' ')
		{
			if (!((*str >= '0' && *str <= '9') || *str == sep))
				return (-1);
		}
		else if (sep == '\0')
		{
			if (!(*str >= '0' && *str <= '9'))
				return (-1);
		}
		str++;
	}
	return (0);
}

/* handles the result of ^ */
void	validate_number_and_seperator(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 2)
	{
		if (is_number_and_seperator(argv[1], ' ') == -1)
			error_message(1);
	}
	else if (argc > 2)
	{
		i = 1;
		while (i < argc)
		{
			if (is_number_and_seperator(argv[i], '\0') == -1)
				error_message(1);
			i++;
		}
	}
}

/* checks for duplicates in int array */
/* uses arr_len as a stopper (no NULL terminator in int arrays) */
int	check_duplicates(int *array, int arr_len)
{
	int i;
	int j;

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