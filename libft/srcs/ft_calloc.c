/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-wong <si-wong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:03:53 by si-wong           #+#    #+#             */
/*   Updated: 2026/02/05 11:01:00 by si-wong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	if ((size != 0 && count > UINT_MAX / size)
		|| (count != 0 && size > UINT_MAX / count))
		res = NULL;
	else
	{
		res = malloc(count * size);
		if (!res)
			return (NULL);
		ft_bzero(res, count * size);
	}
	return (res);
}

/*int	main(void)
{
	size_t count = 2;
	size_t size = 2;
	int *res = ft_calloc(UINT_MAX, UINT_MAX);
	int i = 0;

	if (!res) {
		printf("resisnulll! \n");
		return 0;
	}

	while (i < count)
	{
		printf("%d", res[i]);
		i++;
	}
}*/
