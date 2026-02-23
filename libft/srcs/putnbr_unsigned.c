/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-wong <si-wong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:05:48 by si-wong           #+#    #+#             */
/*   Updated: 2026/02/04 14:08:59 by si-wong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	putnbr_unsigned(unsigned int nb, const char *str)
{
	unsigned int	len;
	char			*base;
	int				count;

	base = NULL;
	if (*str == 'u')
		base = "0123456789";
	else if (*str == 'x')
		base = "0123456789abcdef";
	else if (*str == 'X')
		base = "0123456789ABCDEF";
	len = printf_strlen(base);
	count = 0;
	if (nb >= len)
		count += putnbr_unsigned((nb / len), str);
	count += printf_putchar(base[nb % len]);
	return (count);
}
