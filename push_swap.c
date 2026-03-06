#include "push_swap.h"

t_ops	*initialize_ops(void)
{
	t_ops	*ops;

	ops = (t_ops *)malloc(sizeof(t_ops));
	if (!ops)
		return (NULL);
	ops->sa = "sa";
	ops->sb = "sb";
	ops->ss = "ss";
	ops->pa = "pa";
	ops->pb = "pb";
	ops->ra = "ra";
	ops->rb = "rb";
	ops->rr = "rr";
	ops->rra = "rra";
	ops->rrb = "rrb";
	ops->rrr = "rrr";
	return (ops);
}

t_ps	*initialize_ps()
{
	t_ps *data;

	data = (t_ps *)malloc(sizeof(t_ps));
	data->a = NULL;
	data->b = NULL;
	data->res = NULL;
	data->ops = initialize_ops();
	return data;
}

int	main(int argc, char **argv)
{
	t_ps *data;
	int *res;
	int res_len;

	data = initialize_ps();
	res = NULL;
	if (!argc || !argv || argc < 2)
		return (1);
	res_len = parse_args(argc, argv, &res);
	list_creation(&data->a, res_len, res);

	t_list *current;
	current = data->a;
	while (current)
	{
		printf("%d\n", *(int *)current->content);
		current = current->next;
	}
}