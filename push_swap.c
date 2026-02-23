#include "push_swap.h"

void	error_message(int num)
{
	if (num == 1)
		ft_printf("%s\n", "ERROR: please input numbers only");
	if (num == 2)
		ft_printf("%s\n", "ERROR: duplicate values");
	exit(1);
}

int	main(int argc, char **argv)
{
	t_list *begin_list;

	if (!argc || !argv || argc < 2)
		return (1);
	begin_list = NULL;
	list_creation(argc, argv, &begin_list);
	// t_list *current;
	// current = begin_list;
	// while (current)
	// {
	// 	printf("%d\n", *(int *)current->content);
	// 	current = current->next;
	// }
}