/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ostouayr <ostouayr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:08:57 by ostouayr          #+#    #+#             */
/*   Updated: 2024/11/13 21:46:20 by ostouayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (specifier == 'p')
	{
		write(1, "0x", 2);
		count += ft_print_adress(
				va_arg(args, unsigned long)) + 2;
	}
	else if (specifier == 'd' || specifier == 'i')
		count += ft_putnbr(va_arg(args, int), 10);
	else if (specifier == 'u')
		count += ft_print_unsigned(va_arg(args, unsigned int), 10);
	else if (specifier == 'x' || specifier == 'X')
		count += ft_print_hexa(
				va_arg(args, unsigned int), 16, specifier);
	else if (specifier == '%')
		count += ft_putchar('%');
	return (count);
}

int	helper_function(const char *str, va_list args)
{
	int	count;
	int	check_sign;

	check_sign = 0;
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			check_sign = ft_print_format(*(++str), args);
			if (check_sign == -1)
				return (-1);
			count += check_sign;
		}
		else
		{
			check_sign = write(1, str, 1);
			if (check_sign == -1)
				return (-1);
			count++;
		}
		++str;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		check_sign;

	va_start(args, str);
	count = 0;
	check_sign = 0;
	if (!str || write(1, 0, 0) == -1)
		return (-1);
	count += helper_function(str, args);
	va_end(args);
	return (count);
}
