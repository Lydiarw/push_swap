/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-wong <si-wong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:38:10 by si-wong           #+#    #+#             */
/*   Updated: 2026/02/04 14:11:15 by si-wong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	check_formatter(const char *str, va_list *list);
int	printf_putchar(char c);
int	printf_putstr(char *str);
int	printf_strlen(char *str);
int	print_p(va_list *list);
int	putnbr(long nb);
int	putnbr_pointer(unsigned long nb, char *base);
int	putnbr_unsigned(unsigned int nb, const char *str);

#endif