/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-wong <si-wong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:06:07 by si-wong           #+#    #+#             */
/*   Updated: 2026/02/04 14:08:43 by si-wong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	putnbr(long nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		nb *= -1;
		count += printf_putchar('-');
	}
	if (nb > 9)
		count += putnbr((nb / 10));
	count += printf_putchar(nb % 10 + '0');
	return (count);
}
