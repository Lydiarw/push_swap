/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-wong <si-wong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:06:20 by si-wong           #+#    #+#             */
/*   Updated: 2026/02/04 14:08:24 by si-wong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	printf_putstr(char *str)
{
	int	count;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	count = 0;
	while (*str)
	{
		count += printf_putchar(*str);
		str++;
	}
	return (count);
}
