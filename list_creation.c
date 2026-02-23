#include "push_swap.h"

int	number_and_sep_only(char *str, char sep)
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

int	check_duplicates(t_list **begin_list)
{
	t_list	*current;
	t_list	*temp;

	current = *begin_list;
	while (current->next)
	{
		temp = current->next;
		while (temp)
		{
			if (*(int *)current->content == *(int *)temp->content)
				return (-1);
			temp = temp->next;
		}
		current = current->next;
	}
	return (0);
}

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

void	args_to_list(t_list **begin_list, char **array)
{
	int	*num;

	if (!array)
		return ;
	while (*array)
	{
		num = malloc(sizeof(int));
		if (!num)
			return ;
		*num = ft_atoi(*array);
		if (!*begin_list)
			*begin_list = ft_lstnew(num);
		else
			ft_lstadd_back(begin_list, ft_lstnew(num));
		array++;
	}
	if (check_duplicates(begin_list) == -1)
		error_message(2);
	return ;
}

void list_creation(int argc, char **argv, t_list **begin_list)
{
	char **array;
	int i;

	array = NULL;
	if (argc == 2)
	{
		if (number_and_sep_only(argv[1], ' ') == -1)
			error_message(1);
		array = ft_split(argv[1], ' ');
		args_to_list(begin_list, array);
	}
	else if (argc > 2)
	{
		i = 1;
		while (i < argc)
		{
			if (number_and_sep_only(argv[i], '\0') == -1)
				error_message(1);
			i++;
		}
		args_to_list(begin_list, argv + 1);
	} 
	free_memory(array);
	return;
}