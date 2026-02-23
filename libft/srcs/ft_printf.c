/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-wong <si-wong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:04:37 by si-wong           #+#    #+#             */
/*   Updated: 2026/02/04 14:09:54 by si-wong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	check_formatter(const char *str, va_list *list)
{
	int	count;

	count = 0;
	if (*str == 'c')
		count = printf_putchar((char)va_arg(*list, int));
	else if (*str == 's')
		count = printf_putstr(va_arg(*list, char *));
	else if (*str == 'p')
		count = print_p(list);
	else if (*str == 'd' || *str == 'i')
		count = putnbr(va_arg(*list, int));
	else if (*str == 'u' || *str == 'x' || *str == 'X')
		count = putnbr_unsigned(va_arg(*list, int), str);
	else if (*str == '%')
		count = printf_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		letter_count;

	if (!*str)
		return (0);
	letter_count = 0;
	va_start(list, str);
	while (*str)
	{
		if (*str == '%')
			letter_count += check_formatter(++str, &list);
		else
			letter_count += printf_putchar(*str);
		str++;
	}
	va_end(list);
	return (letter_count);
}

/*int	main(void)
{
// //print_char-DONE
//     printf("c ori: %c%c%c%c\n", 'm', 'e', 'o', 'w');
//     int char_count = ft_printf("c: %c%c%c%c\n", 'm', 'e', 'o', 'w');
//     printf("char count: %i\n", char_count);
//     printf(" %c %c %c ", 0, '1', '2');
//     printf("\n");
//     ft_printf(" %c %c %c ", 0, '1', '2');

// //print_str-DONE
//     char *null_str = NULL;

	// printf("hi all % \n", "hi");
	// int str_count = ft_printf("hi all % m\n", "hi");
	// printf("s count: %i\n", str_count);

// //print pointer add-DONE
//     char test = 5;

//     printf("%p\n", &test);
//     int p_count = ft_printf("%p\n", &test);
//     printf("p_count: %i\n", p_count);

// //print base 10-DONE
//     long num = 5;
//     long nem = 2;

//     printf("%d %d\n", num, nem);
//     int d_count = ft_printf("%d %d\n", num, nem);
//     printf("d_count: %d\n", d_count);
//     printf("%i %i\n", num, nem);
//     int i_count = ft_printf("%i %i\n", num, nem);
//     printf("i_count: %i\n", i_count);

// //print_u_x_X -DONE
	// int num = -42;

	// printf("u: %u\n", num);
	// int u_count = ft_printf("u: %u\n", num);
	// printf("u_count: %i\n", u_count);
	// printf("---------x_X--------\n");
	// printf("x: %x\n", num);
	// int x_count = ft_printf("x: %x\n", num);
	// printf("x_count: %i\n", x_count);
	// printf("X: %X\n", num);
	// int X_count = ft_printf("X: %X\n", num);
	// printf("X_count: %i\n", X_count);

// //print_% -DONE
// 	printf("%%\n");
// 	int p_count = ft_printf("%%\n");
// 	printf("percent count: %i\n", p_count);
}*/