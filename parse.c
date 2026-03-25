#include "push_swap.h"

/* convert raw input data into an array of strings */
char	**get_array(int argc, char **argv)
{
	char	**array;
	int		i;

	array = NULL;
	if (argc == 2)
		array = ft_split(argv[1], ' ');
	else if (argc > 2)
	{
		array = (char **)malloc(argc * sizeof(char *));
		i = 0;
		while (++i < argc)
			array[i - 1] = ft_strdup(argv[i]);
		array[i - 1] = NULL;
	}
	return (array);
}

/* converts the array of strs into an array of ints */
/* returning count cuz there's no NULL to signify the end */
int	*to_int_array(char **array, int *length)
{
	int	*res;
	int	i;
	int	len;

	len = ft_arrlen(array);
	res = (int *)malloc(len * sizeof(int));
	i = -1;
	while (array[++i])
		res[i] = ft_atoi(array[i]);
	*length = len;
	return (res);
}

// 1. validate the arguments
// 2. convert to an int array (get_array)
// 3. check duplicates
// 4. convert string array to int array
// 5. free input array
// 6. return array length
int	parse_args(int argc, char **argv, int **res)
{
	char **input_array;
	int arr_len;

	arr_len = 0;
	validate_number_and_seperator(argc, argv);
	input_array = get_array(argc, argv);
	*res = to_int_array(input_array, &arr_len);
	if (check_duplicates(*res, arr_len) == -1)
		error_message(2);
	free_memory(input_array);
	return (arr_len);
}