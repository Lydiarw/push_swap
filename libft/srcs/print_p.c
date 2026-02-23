/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-wong <si-wong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:04:13 by si-wong           #+#    #+#             */
/*   Updated: 2026/02/04 14:09:28 by si-wong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_p(va_list *list)
{
	void	*ptr;
	int		count;

	ptr = va_arg(*list, void *);
	if (!ptr)
		count = printf_putstr("(nil)");
	else
	{
		printf_putstr("0x");
		count = 2;
		count += putnbr_pointer((unsigned long)ptr, "0123456789abcdef");
	}
	return (count);
}
