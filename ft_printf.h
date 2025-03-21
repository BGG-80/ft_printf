/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blgutier <blgutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:16:40 by blgutier          #+#    #+#             */
/*   Updated: 2025/03/20 21:53:47 by blgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

int	ft_printf(char const *format, ...);
int	printf_findtype(va_list args, char *format);
int	printf_putchar(char c);
int	printf_putstr(char *str);
int	printf_putnbr(int nbr);
int	printf_putnbr_unsigned(unsigned int nbr);
int	printf_puthex(unsigned long long nbr, int upcase);
int	printf_putptr(void *ptr);

#endif
