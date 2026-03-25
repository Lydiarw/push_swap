#include "push_swap.h"

int	same_direction(int a, int b)
{
	if ((a > 0 && b > 0) || (a < 0 && b < 0))
		return (1);
	return (0);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}