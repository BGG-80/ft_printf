/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blgutier <blgutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 22:10:34 by blgutier          #+#    #+#             */
/*   Updated: 2025/03/20 21:34:49 by blgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	printf_findtype(va_list args, char *format)
{
	int	count;

	count = 0;
	if (*format == 'c')
		count += printf_putchar(va_arg(args, int));
	else if (*format == 's')
		count += printf_putstr(va_arg(args, char *));
	else if (*format == 'd' || *format == 'i')
		count += printf_putnbr(va_arg(args, int));
	else if (*format == 'u')
		count += printf_putnbr_unsigned(va_arg(args, unsigned int));
	else if (*format == 'x')
		count += printf_puthex(va_arg(args, unsigned int), 1);
	else if (*format == 'X')
		count += printf_puthex(va_arg(args, unsigned int), 0);
	else if (*format == 'p')
		count += printf_putptr(va_arg(args, void *));
	else if (*format == '%')
		count += printf_putchar('%');
	return (count);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += printf_findtype(args, (char *)format);
		}
		else
			count += printf_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
