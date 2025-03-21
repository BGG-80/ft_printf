/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blgutier <blgutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:17:19 by blgutier          #+#    #+#             */
/*   Updated: 2025/03/20 21:49:27 by blgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write (1, "(null)", 6));
	while (str[i])
	{
		printf_putchar(str[i]);
		i++;
	}
	return (i);
}

int	printf_putnbr(int nbr)
{
	int	count;

	count = 0;
	if (nbr == -2147483648)
	{
		count += printf_putstr("-2147483648");
		return (count);
	}
	if (nbr < 0)
	{
		count += printf_putchar('-');
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		count += printf_putnbr(nbr / 10);
		count += printf_putchar((nbr % 10) + '0');
	}
	else
		count += printf_putchar(nbr + '0');
	return (count);
}

int	printf_putnbr_unsigned(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr > 9)
		count += printf_putnbr_unsigned(nbr / 10);
	count += printf_putchar((nbr % 10) + '0');
	return (count);
}

int	printf_puthex(unsigned long long nbr, int upcase)
{
	char	*hex;
	int		count;

	count = 0;
	if (upcase)
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (nbr > 15)
		count += printf_puthex((nbr / 16), upcase);
	count += printf_putchar (hex[nbr % 16]);
	return (count);
}

int	printf_putptr(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (printf_putstr("(nil)"));
	count += printf_putstr("0x");
	count += printf_puthex((unsigned long long)ptr, 1);
	return (count);
}
