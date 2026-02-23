/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-wong <si-wong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:05:33 by si-wong           #+#    #+#             */
/*   Updated: 2026/02/04 14:09:12 by si-wong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	putnbr_pointer(unsigned long nb, char *base)
{
	unsigned long	len;
	int				count;

	len = printf_strlen(base);
	count = 0;
	if (nb >= len)
		count += putnbr_pointer((nb / len), base);
	count += printf_putchar(base[nb % len]);
	return (count);
}
